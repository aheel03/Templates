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
 
 
bool vis[1005][1005];
ll level[1005][1005];
vector<pair<ll,ll>> nodelist;
vector<ll> dx={0,0,1,-1}, dy={-1,1,0,0};
vector<vector<char>> grid(1005,vector<char>(1005,'#'));
 
 
void solve(){
 
}
 
void dfs(ll i, ll j, ll n, ll m){
    if(i<0 || i>=n || j<0 || j>=m) return;
    if(grid[i][j]!='.') return;
    if(vis[i][j]) return;
 
    vis[i][j]=true;
    loop(k,0,4){
        dfs(dx[k]+i,dy[k]+j,n,m);
    }
}
 
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    /* ll t;cin>>t;
    while(t--) solve(); */
    pll source_node, dest_node;
    ll n,m;cin>>n>>m;
    loop(i,0,n){
        loop(j,0,m){
            cin>>grid[i][j];
            //if(grid[i][j]=='.') nodelist.pb({i,j});
            if(grid[i][j]=='A') source_node={i,j};
            if(grid[i][j]=='B') dest_node={i,j};
        }
    }
    queue<pll> q;
    q.push(source_node);
    while(!q.empty()){
        pll curr_node=q.front();
        q.pop();
        loop(k,0,4){
            ll x=dx[k]+curr_node.ft;
            ll y=dy[k]+curr_node.sc;
            if(x>=0 && x<n && y>=0 && y<m){
                if(!vis[x][y] && (grid[x][y]=='.' || grid[x][y]=='B')){
                    q.push({x,y});
                    vis[x][y]=1;
                    level[x][y]=level[curr_node.ft][curr_node.sc]+1;
                }
            }
        }
    }
    ll totallev=level[dest_node.ft][dest_node.sc];
    if(totallev==0){
        No;
        return 0;
    }
    Yes;
    cout<<totallev<<endl;
    queue<pll> Q;
    Q.push(dest_node);
    string ans;
    ll level_count=1;
    while(!Q.empty()){
        pll node=Q.front();
        Q.pop();
        loop(k,0,4){
            ll x=dx[k]+node.ft;
            ll y=dy[k]+node.sc;
            if(x>=0 && x<n && y>=0 && y<m){
                if(totallev==level_count){
                    if(grid[x][y]=='A'){
                        if(dy[k]==-1) ans.pb('R');
                        if(dy[k]==1) ans.pb('L');
                        if(dx[k]==-1) ans.pb('D');
                        if(dx[k]==1) ans.pb('U');
                        reverse(all(ans));
                        cout<<ans<<endl;
                        return 0;
                    }
                }else if(level[x][y]==totallev-level_count){
                    if(dy[k]==-1) ans.pb('R');
                    if(dy[k]==1) ans.pb('L');
                    if(dx[k]==-1) ans.pb('D');
                    if(dx[k]==1) ans.pb('U');
                    Q.push({x,y});
                    level_count++;
                    break;
                }
            }
        }
    }
 
}
