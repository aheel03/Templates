// cses problem link : https://cses.fi/problemset/task/1130
// You are given a tree consisting of n nodes.
// A matching is a set of edges where each node is an endpoint of at most one edge. 
// What is the maximum number of edges in a matching?
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


vector<ll> graph[N];
vector<bool> vis(N,false);

vector<vector<ll>> dp(N,vector<ll>(2,-1ll));

vector<ll> makepref(vector<ll> &v){
    ll n=v.size();
    vector<ll> pref(n,0ll);
    pref[0]=v[0];
    loop(i,1,n){
        pref[i]=v[i]+pref[i-1];
    }
    return pref;
}

vector<ll> makesuff(vector<ll> &v){
    ll n=v.size();
    vector<ll> suff(n,0ll);
    suff[n-1]=v[n-1];
    for(int i=n-2;i>=0;i--){
        suff[i]=v[i]+suff[i+1];
    }
    return suff;
}

 
ll solve(ll node,ll parent,ll x){
    if(dp[node][x]!=-1) return dp[node][x];
    if(graph[node].size()==1 && node!=1){
        dp[node][1]=0;
        dp[node][0]=0;
        return dp[node][x];
    }

    if(x==0){
        ll mx=0;
        for(auto child:graph[node]){
            if(child==parent) continue;
            ll a=solve(child,node,0);
            ll b=solve(child,node,1);
            mx+=max(a,b);
        }
        dp[node][0]=mx;
        return dp[node][0];
    }else{
        vector<ll> children;
        vector<ll> children_value;
        for(auto child:graph[node]){
            if(child!=parent){
                children_value.push_back(max(solve(child,node,0),solve(child,node,1)));
                children.push_back(child);
            }
        }
        vector<ll> pref=makepref(children_value);
        vector<ll> suff=makesuff(children_value);
        ll n=children.size();
        ll mx=-1;
        if(n>=3){
            loop(i,1,n-1){
                mx=max(mx,1+pref[i-1]+solve(children[i],node,0)+suff[i+1]);
            }
        }
        if(n>=2){
            mx=max(mx,1+solve(children[0],node,0)+suff[1]);
            mx=max(mx,1+pref[n-2]+solve(children[n-1],node,0));
        }
        if(n==1){
            mx=1+solve(children[0],node,0);
        }
        
        dp[node][1]=mx;
        return dp[node][1];
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
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    
    cout<<max(solve(1,1,0),solve(1,1,1))<<endl;
    // loop(i,1,n+1){
    //     cout<<"node "<<i<<" : "<<dp[i][0]<<" "<<dp[i][1]<<endl;
    // }
}
