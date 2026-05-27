// Count y where x|y == x: Number of elements y that are subsets of x.
// Count y where x&y == x: Number of elements y that are supersets of x.
// Count y where x&y != 0: Total elements n minus those where x&y == 0.
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long int              ll;
typedef vector<long long int>      vll;
typedef pair<long long int,long long int>  pll;
typedef long double                lld;
typedef tree<int, null_type, less_equal<int>, 
                  rb_tree_tag, tree_order_statistics_node_update> pbds;

#define loop(i,k,n)                for(ll i=k;i<n;i++)
#define looprev(i,n,k)             for(ll i=n-1;i>=k;i--)
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
#define rall(x)                    (x).rbegin(),(x).rend()
#define inparr(arr,n)              ll arr[n]; loop(i,0,n) cin>>arr[i]
#define inpvec(v,n)                vector<ll> v(n); for(auto &i:v) cin>>i
#define CEIL(x,y)                  (((x)+(y)-1)/(y))
#define ase(st,val)                (st.find(val)!=st.end())
#define set_bits                   __builtin_popcountll
#define MOD1                       1000000007
#define MOD2                       998244353
#define INF                        1e18
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


const ll N=1e6+20;
const double EPS = 1e-9;
const ll MOD=MOD2;

inline ll msb_idx(ll n) {
    if(n==0) return -1;
    return 63-__builtin_clzll(n); 
}

void solve(){
    ll n;
    cin>>n;
    inparr(a,n);
    ll k=msb_idx(N);
    ll MAXN=(1ll<<(k+1))-1;
    vector<ll> cnt(MAXN,0ll);
    loop(i,0,n) cnt[a[i]]++;
    //cout<<MAXN<<endl;
    vector<ll> dpAnd(MAXN,0ll);
    vector<ll> dpOr(MAXN,0ll);
    vector<ll> dpSub(MAXN,0ll);
    loop(i,0,MAXN){
        dpAnd[i]=cnt[i];
        dpOr[i]=cnt[i];
    }
    for(int i=0;i<=k;i++){
        for(int mask=0;mask<(1ll<<(k+1));mask++){
            if(mask&(1ll<<i)){
                dpAnd[mask]+=dpAnd[mask^(1ll<<i)];
            }
        }
        for(int mask=(1ll<<(k+1))-1;mask>0;mask--){
            if(mask&(1ll<<i)){
                dpOr[mask^(1ll<<i)]+=dpOr[mask];
            }
        }
    }
    for(int mask=0;mask<(1ll<<(k+1));mask++){
        ll comple = (mask^((1ll<<(k+1))-1));
        dpSub[mask]+=dpAnd[comple];
    }
    loop(i,0,n){
        cout<<dpAnd[a[i]]<<" "<<dpOr[a[i]]<<" "<<n-dpSub[a[i]]<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    ll t=1;
    //cin>>t;
    while(t--){
       solve();
    }
}
