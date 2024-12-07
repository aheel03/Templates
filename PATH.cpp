#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef long long int            ll;
typedef vector<ll>               vll;
typedef map<ll,ll>               mll;
typedef pair<ll,ll>              pll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, 
tree_order_statistics_node_update> ordered_set;
 
#define loop(i,k,n)              for(ll i=k;i<n;i++)
#define pb                       push_back
#define ft                       first 
#define sc                       second
#define yes                      cout<<"Yes"<<endl
#define no                       cout<<"No"<<endl
#define Yes                      cout<<"YES"<<endl
#define No                       cout<<"NO"<<endl
#define Alice                    cout<<"Alice"<<endl
#define Bob                      cout<<"Bob"<<endl
#define newl                     cout<<"\n"
#define clean                    fflush(stdout)
#define FLOOR(x,y)               (ll(floor(double(x)/y)))
#define CEIL(x,y)                (ll(ceil(double(x)/y)))
#define max3(a,b,c)              max(a,max(b,c))
#define min3(a,b,c)              min(a,min(b,c))
#define all(v)                   v.begin(),v.end()
#define rall(v)                  v.rbegin(),v.rend()
#define inparr(arr,n)            ll arr[n]; loop(i,0,n) cin >> arr[i]
#define inpvec(v,n)              vll v(n); for(auto &i:v) cin >> i
const ll M=1e9+7;
const ll INF=1e15;
const ll N=2e5+5;
 
vector<ll> graph[N];
bool vis[N];
vector<vector<ll>> ans;
ll level[N];
/* bool vis[1005][1005];
ll level[1005][1005];
vector<pair<ll,ll>> nodelist;
vector<ll> dx={0,0,1,-1}, dy={-1,1,0,0};
vector<vector<char>> grid(1005,vector<char>(1005,'#')); */
 
 
void solve(){
 
}
 
void dfs(ll node, vector<ll>& vec){
    if(vis[node]) return;
    vis[node]=true;
    vec.pb(node);
    for(auto child:graph[node]){
        dfs(child,vec);
    }
}
 
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    /* ll t;cin>>t;
    while(t--) solve(); */
    ll n,m;
    cin>>n>>m;
    loop(i,0,m){
        ll x,y;
        cin>>x>>y;
        graph[x].pb(y);
        graph[y].pb(x);
    }
    queue<ll> q;
    ll par[n];
    q.push(1);
    par[1]=1;
    vis[1]=1;
    while(!q.empty()){
        ll parent=q.front();
        q.pop();
        for(auto child:graph[parent]){
            if(vis[child]) continue;
            q.push(child);
            vis[child]=true;
            par[child]=parent;
            level[child]=level[parent]+1;
        }
    }
    if(level[n]==0){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    ll v=n;
    vll ans;
    ans.pb(v);
    loop(i,0,level[n]){
        ans.pb(par[v]);
        v=par[v];
    }
    cout<<ans.size()<<endl;
    reverse(all(ans));
    for(auto v:ans) cout<<v<<" ";
 
}
