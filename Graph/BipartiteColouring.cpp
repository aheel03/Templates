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
ll col[N];
 
vector<vector<ll>> ans;
ll level[N];
/* bool vis[1005][1005];
ll level[1005][1005];
vector<pair<ll,ll>> nodelist;
vector<ll> dx={0,0,1,-1}, dy={-1,1,0,0};
vector<vector<char>> grid(1005,vector<char>(1005,'#')); */
 
 
void solve(){
 
}
 
void dfs(ll node){
    if(vis[node]) return;
    vis[node]=true;
    for(auto child:graph[node]){
        if(col[node]==1){
            col[child]=2;
        }else{
            col[child]=1;
        }
        dfs(child);
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
    vector<pair<ll,ll>> edges;
    loop(i,0,m){
        ll x,y;
        cin>>x>>y;
        edges.pb({x,y});
        graph[x].pb(y);
        graph[y].pb(x);
    }
    col[1]=1;
    loop(i,1,n+1){
        if(vis[i]) continue;
        col[i]=1;
        dfs(i);
    }
    //dfs(1);
    for(auto [v1,v2]:edges){
        if(col[v1]==col[v2]){
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        }
    }
    loop(i,1,n+1) cout<<col[i]<<" ";
}
