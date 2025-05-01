// https://cses.fi/problemset/task/1675/
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

    

vector<ll> par(N,-1);
vector<ll> set_size(N,0ll);
// initialize the DSU with make_set() on all nodes

void make_set(ll node){
    par[node]=node;
    set_size[node]=1;
}

ll find_set(ll node){
    if(node==par[node]){
        return node;
    }
    return par[node]=find_set(par[node]);
}

void union_sets(ll a,ll b){
    a=find_set(a);
    b=find_set(b);

    if(a!=b){
        if(set_size[a]<set_size[b]) swap(a,b);
        par[b]=a;
        set_size[a]+=set_size[b];
    }
}

 
 
 
void solve(){
    ll n,m;
    cin>>n>>m;
    vector<pair<ll,pair<ll,ll>>> edges;
    loop(i,1,n+1) make_set(i);
    loop(i,0,m){
        ll u,v,wt;
        cin>>u>>v>>wt;
        edges.push_back({wt,{u,v}});
    }
    ll ans=0;
    sort(edges.begin(),edges.end());
    loop(i,0,m){
        auto bruh=edges[i];
        ll u=bruh.second.first;
        ll v=bruh.second.second;
        ll wt=bruh.first;
        if(find_set(u)==find_set(v)){
            continue;
        }
        union_sets(u,v);
        ans+=wt;
    }
    set<ll> s;
    loop(i,1,n+1){
        s.insert(find_set(i));
    }
    if(s.size()!=1){
        cout<<"IMPOSSIBLE\n";
        return;
    }
    cout<<ans<<endl;
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
