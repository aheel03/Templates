// cses problem link : https://cses.fi/problemset/task/1131
// find tree diameter

#include <bits/stdc++.h>
using namespace std;

typedef long long int            ll;

#define loop(i,k,n)              for(ll i=k;i<n;i++)
#define f                        first 
#define s                        second
#define Yes                      cout<<"YES"<<endl
#define No                       cout<<"NO"<<endl
#define newl                     cout<<"\n"
#define clean                    fflush(stdout)
#define all(v)                   v.begin(),v.end()
#define inparr(arr,n)            ll arr[n]; loop(i,0,n) cin>>arr[i]
#define inpvec(v,n)              vll v(n); for(auto &i:v) cin>>i

const ll M=998244353;
//const ll M=1e9+7;
const ll INF=1e15;
const ll N=2e5+5;

/* vector<vector<ll>> ans;
ll level[N];
bool vis[1005][1005];
bool visA[1005][1005];
ll level[1005][1005];
ll levelA[1005][1005];
pll par[1005][1005];
vector<pair<ll,ll>> nodelist;
vector<ll> dx={0,0,1,-1}, dy={-1,1,0,0};
vector<vector<char>> grid(1005,vector<char>(1005,'#')); */


vector<ll> tree[N];
vector<bool> vis(N,false);
vector<ll> height(N,-1ll);

vector<vector<ll>> dp(N,vector<ll>(2,-1ll));

void dfs(ll node,ll parent){
    height[node]=0;
    for(ll child:tree[node]) {
        if(child!=parent){
            dfs(child, node);
            height[node] = max(height[node], height[child]+1);
        }
    }
}

 
ll solve(ll node,ll parent,ll x){
    if(dp[node][x]!=-1) return dp[node][x];
    if(tree[node].size()==1 && node!=1){
        dp[node][1]=0;
        dp[node][0]=0;
        return dp[node][x];
    }

    if(x==0){
        ll mx=0;
        for(auto child:tree[node]){
            if(child==parent) continue;
            mx=max(mx,max(solve(child,node,0),solve(child,node,1)));
        }
        dp[node][0]=mx;
        return dp[node][0];
    }else{
        vector<ll> children_value;
        for(auto child:tree[node]){
            if(child!=parent){
                children_value.push_back(height[child]);
            }
        }

        if(children_value.size()==1){
            return dp[node][1]=1+children_value[0];
        }else{
            sort(children_value.rbegin(),children_value.rend());
            return dp[node][1]=2+children_value[0]+children_value[1];
        }
    }
}

 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    /* ll t;cin>>t;
    while(t--) solve(); */
    ll n;
    cin>>n;
    if(n==1){
        cout<<0<<endl;
        return 0;
    }
    loop(i,2,n+1){
        ll x,y;
        cin>>x>>y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    dfs(1,1);
    cout<<max(solve(1,1,0),solve(1,1,1))<<endl;
    
    // loop(i,1,n+1){
    //     cout<<"node "<<i<<" : "<<height[i]<<endl;
    // }
}
