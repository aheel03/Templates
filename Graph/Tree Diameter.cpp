// https://judge.yosupo.jp/problem/tree_diameter

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long int              ll;
typedef double                     db;
typedef long double                ld;
typedef vector<long long int>      vll;
typedef pair<long long int,long long int>  pll;
typedef vector<pair<long long int,long long int>> vpll;
typedef tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#define loop(i,k,n)                for(ll i=k;i<n;i++)
#define ft                         first 
#define sc                         second
#define pb                         push_back
#define sz(x)                      ((int)(x).size())
#define yes                        cout<<"Yes"<<endl
#define no                         cout<<"No"<<endl
#define Yes                        cout<<"YES"<<endl
#define No                         cout<<"NO"<<endl
#define Alice                      cout<<"Alice"<<endl
#define Bob                        cout<<"Bob"<<endl
#define newl                       cout<<"\n"
#define clean                      fflush(stdout)
#define all(x)                     (x).begin(),(x).end()
#define inparr(arr,n)              ll arr[n]; loop(i,0,n) cin>>arr[i]
#define inpvec(v,n)                vector<ll> v(n); for(auto &i:v) cin>>i
#define CEIL(x,y)                  ((x+y-1)/y)
#define set_bits                   __builtin_popcountll
#define PI                         3.141592653589793238462
#define __1                        cout<<-1<<endl;
template<class T>void _print(T t){cerr<<t;}
template<class T,class V>void _print(pair<T,V>p){cerr<<"{";_print(p.ft);cerr<<",";_print(p.sc);cerr<<"}";}
template<class T>void _print(const vector<T>&v){cerr<<"[ ";for(T i:v){_print(i);cerr<<" ";}cerr<<"]";}
template<class T>void _print(const set<T>&v){cerr<<"[ ";for(T i:v){_print(i);cerr<<" ";}cerr << "]";}
template<class T>void _print(const multiset<T>&v){cerr<<"[ ";for(T i:v){_print(i);cerr<<" ";}cerr<<"]";}
template<class T,class V>void _print(const map<T,V>&v){cerr<<"[ ";for(auto i:v){_print(i);cerr<<" ";}cerr<<"]";}
void _debug_out(string s) { cerr << endl; }
template <typename T, typename... Args>
void _debug_out(string s, T x, Args... args) {
    while (!s.empty() && s[0] == ' ') s.erase(0, 1);
    for (int i = 0, b = 0; i < (int)s.size(); i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') b++;
        else if (s[i] == ')' || s[i] == '}' || s[i] == ']') b--;
        else if (s[i] == ',' && b == 0) {
            cerr << s.substr(0, i) << " ";_print(x);
            if (sizeof...(args)) cerr << " ";
            _debug_out(s.substr(i + 1), args...);return;}}
    cerr << s << " ";_print(x);
    if (sizeof...(args)) cerr << " ";_debug_out("", args...);}
#ifndef ONLINE_JUDGE
#define debug(...) _debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...)
#endif


const ll N=5e5+5;
const ll MOD=998244353;
const ll INF=1e18;
const long double sotoeps=1e-5;
const double EPS = 1e-9;

vector<pll> graph[N];
vector<ll> lev(N,0ll);
vector<ll> par(N,-1);


void dfs(ll node,ll parent){
    for(auto [child,val]:graph[node]){
        if(child==parent) continue;
        par[child]=node;
        lev[child]=lev[node]+val;
        dfs(child,node);
    }
}


void solve(){
    ll n;
    cin>>n;
    loop(i,0,n-1){
        ll u,v,x;
        cin>>u>>v>>x;
        graph[u].pb({v,x});
        graph[v].pb({u,x});
    }
    dfs(0,-1);
    ll newroot;
    ll mx=-1;
    loop(i,0,n){
        if(lev[i]>mx){
            mx=lev[i];
            newroot=i;
        }
        lev[i]=0ll;
        par[i]=-1;
    }
    dfs(newroot,-1);
    ll ans1=newroot;
    ll ans2=-1;
    mx=-1;
    loop(i,0,n){
        if(lev[i]>mx){
            mx=lev[i];
            ans2=i;
        }
    }

    vll ans;
    ans.push_back(ans2);

    while(1){
        ans.push_back(par[ans2]);
        ans2=par[ans2];
        if(par[ans2]==-1)break;
    }
    cout<<mx<<" "<<sz(ans)<<endl;
    for(auto c:ans){
        cout<<c<<" ";
    }
    newl;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);



    ll t=1;
    //cin>>t;
    loop(i,1,t+1){
        //cout<<"Case "<<i<<": ";
        solve();
        //cout<<endl;
    }
    //solve();
}

