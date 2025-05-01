#include <bits/stdc++.h>
using namespace std;
 
typedef long long int            ll;
 
#define loop(i,k,n)              for(ll i=k;i<n;i++)
#define f                        first 
#define s                        second
#define Yes                      cout<<"Yes"<<endl
#define No                       cout<<"No"<<endl
#define newl                     cout<<"\n"
#define clean                    fflush(stdout)
#define all(v)                   v.begin(),v.end()
#define inparr(arr,n)            ll arr[n]; loop(i,0,n) cin>>arr[i]
#define inpvec(v,n)              vector<ll> v(n); for(auto &i:v) cin>>i
#define CEIL(x,y)                (ll(ceil(double(x)/double(y))))
 
const ll M=998244353;
const ll INF=1e16;
//const ll N=1e6+5;

const ll N = 3e5 + 9;
vector<pair<ll,ll>> graph[N];
vector<bool> vis(N,false);

    

 
 
 
void solve(){
    ll n,m;
    cin>>n>>m;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    loop(i,0,m){
        ll u,v,wt;
        cin>>u>>v>>wt;
        graph[u].push_back({v,wt});
        graph[v].push_back({u,wt});
    }
    ll totalcost=0;
    ll count=0;
    pq.push({0,1});
    while(!pq.empty() && count<n){
        auto [cost,node]=pq.top();
        pq.pop();
        if(vis[node]) continue;
        vis[node]=true;

        totalcost+=cost;
        count++;

        for(auto [child,wt]:graph[node]){
            if(vis[child]) continue;
            pq.push({wt,child});
        }
    }

    if(count==n){
        cout<<totalcost<<endl;
    }else{
        cout<<"IMPOSSIBLE\n";
    }
}
 
 
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // ll t;
    // cin>>t;
    // while(t--){
    //     solve();
    // }
    solve();
}
