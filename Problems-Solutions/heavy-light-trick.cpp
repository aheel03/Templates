#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long int              ll;
typedef vector<long long int>      vll;
typedef pair<long long,long long>  pll;
typedef complex<long long int>     point;
typedef complex<double>            pointdb;
typedef tree<int, null_type, less_equal<int>, 
                  rb_tree_tag, tree_order_statistics_node_update> pbds;

#define loop(i,k,n)                for(ll i=k;i<n;i++)
#define f                          first 
#define s                          second
#define pb                         push_back
#define yes                        cout<<"Yes"<<endl
#define no                         cout<<"No"<<endl
#define Yes                        cout<<"YES"<<endl
#define No                         cout<<"NO"<<endl
#define newl                       cout<<"\n"
#define clean                      fflush(stdout)
#define all(v)                     v.begin(),v.end()
#define inparr(arr,n)              ll arr[n]; loop(i,0,n) cin>>arr[i]
#define inpvec(v,n)                vector<ll> v(n); for(auto &i:v) cin>>i
#define CEIL(xx,yy)                  ((xx+yy-1)/yy)

const ll INF=1e16;

const double EPS = 1e-9;
//const ll M=998244353;
const ll M=1e9+7;
const ll N=1e6+5;

vector<ll> graph[N];
set<ll> collec[N];
vector<ll> color(N,-1);
vector<ll> ans(N,0);
vector<map<ll,ll>> cnt(N);
vector<ll> mx(N,-1);
vector<ll> unians(N,-1);


void dfs(ll node,ll par){
    for(auto child:graph[node]){
        if(child!=par){
            dfs(child,node);
            if(cnt[node].size()<cnt[child].size()){
                swap(cnt[node],cnt[child]);
                ans[node]=ans[child];
                mx[node]=mx[child];
            }
            for(auto [a,b]:cnt[child]){
                cnt[node][a]+=b;
                if(cnt[node][a]==mx[node]){
                    ans[node]+=a;
                }else if(cnt[node][a]>mx[node]){
                    ans[node]=a;
                    mx[node]=cnt[node][a];
                }
            }
        }
    }
}




void solve(){
    ll n;
    cin>>n;
    loop(i,1,n+1){
        cin>>color[i];
        cnt[i][color[i]]=1;
        ans[i]=color[i];
        mx[i]=1;
    }
    loop(i,0,n-1){
        ll a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1,-1);
    loop(i,1,n+1){
        cout<<ans[i]<<" ";
    }
}

int main()
{ 
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // ll t;
    // cin>>t;
    // while(t--){
    //    solve();
    // }
    solve();
}
