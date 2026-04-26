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
#define for_(item,vec)             for(auto item:vec)
#define ft                         first 
#define sc                         second
#define pb                         push_back
#define sz(x)                      ((int)(x).size())
#define sumvec(vec)                (accumulate(vec.begin(),vec.end(),0LL))
#define sumarr(arr,n)              (accumulate(arr,arr+n,0LL))
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


const ll N=1e6;
const double EPS = 1e-9;
const ll MOD=MOD2;

// pair<ll,ll> largest_2_power_smaller_than_or_eq(ll n){
//     ll num=1ll,power=0ll;
//     while(num<=n){num*=2;power++;}
//     num/=2;power--;
//     return make_pair(num,power);}

// pair<ll,ll> smallest_2_power_larger_than_or_eq(ll n){
//     ll num=1ll,power=0ll;
//     while(num<n){num*=2;power++;}
//     return make_pair(num,power);}

// call FACTMOD() in int main()
// vll factm(N,1ll);
// vll invf(N,1ll);

// ll binpow(ll a,ll n,ll m){
//     if(n==0) return 1ll;
//     ll x=binpow(a,n/2,m);
//     if(n&1ll) return (a*((x*x)%m))%m;
//     else return (x*x)%m;}

// void FACTMOD(ll n,ll m){
//     loop(i,2,n)
//         factm[i]=(factm[i-1]*i)%m;
//     invf[n-1]=binpow(factm[n-1],m-2,m);
//     for(ll i=n-1;i>=1;i--)
//         invf[i-1]=(invf[i]*i)%m;}

// ll nCr(ll n, ll r, ll m) {
//     if(r<0 || r>n) return 0ll;
//     return factm[n]*invf[r]%m*invf[n-r]%m;}


// vector<ll> phi(N+1,0ll);
// vector<ll> SPF(N,0ll);
// vector<ll> primes;
// //call phi_1_to_n(N) and BuildSPF(N); in int main
// void phi_1_to_n(int n) {
//     for(int i=0;i<=n;i++) phi[i]=i;
//     for(int i=2;i<=n;i++){
//         if(phi[i]!=i) continue;
//         for(int j=i;j<=n;j+=i)phi[j]-=phi[j]/i;}}

// void BuildSPF(ll n){
//     for(ll i=2;i<n;i++){
//         if(SPF[i]==0) {
//             SPF[i]=i;primes.push_back(i);
//         }
//         for(ll j=0;j<primes.size() && i*primes[j]<n;j++) {
//             SPF[i*primes[j]]=primes[j];
//             if(primes[j]==SPF[i]) break;
//         }
//     }
// }

// void divisor_generate(ll idx, ll cur_d,
//                     vector<pair<ll,ll>>& factors,
//                     vector<ll>& result){
//     if(idx==factors.size()){
//         result.push_back(cur_d);return;
//     }
//     auto [p,exp]=factors[idx];
//     ll p_pow=1;
//     for(ll i=0;i<=exp;i++){
//         divisor_generate(idx+1,p_pow*cur_d,factors,result);
//         p_pow*=p;
//     }
// }

// vector<ll> get_divisors(ll n){
//     if(n==1) return {1};
//     vector<ll> divisors;
//     vector<pair<ll,ll>> factors;
//     while(n>1){
//         ll p=SPF[n],cnt=0;
//         while(n%p==0){n/=p;cnt++;}
//         factors.push_back({p,cnt});
//     }
//     divisor_generate(0,1,factors,divisors);
//     sort(divisors.begin(),divisors.end());
//     return divisors;
// }


// ll A_by_B_mod(ll a,ll b){
//     a=a%MOD;b=b%MOD;    
//     return (a*(binpow(b,MOD-2,MOD)))%MOD;
// }



vector<ll> makepref(vector<ll> &v){
    ll n=v.size();
    vector<ll> pref(n,0ll);
    pref[0]=v[0];
    loop(i,1,n){
        pref[i]=v[i]+pref[i-1];
    }
    return pref;
}


void solve(){
    string s;
    cin>>s;
    ll n=sz(s);
    vll dp(n,0ll);
    vll pref_straight(n,0ll);
    ll l=-1,r=0;
    vector<bool> dependence_ache(n,false);
    vll suff(n,0ll);
    for(ll i=n-2;i>=0;i--){
        suff[i]=suff[i+1];
        if(s[i]==':' && s[i+1]==')'){
            suff[i]++;
        }
    }
    loop(i,1,n){
        pref_straight[i]=pref_straight[i-1];
        dp[i]=dp[i-1];
        if(s[i-1]==':' && s[i]==')'){
            pref_straight[i]++;
            if(pref_straight[i]>dp[i]){
                l=-1;
            }
            dp[i]=max(dp[i],pref_straight[i]);
        }else if(s[i-1]=='(' && s[i]==':'){
            bool ok=false;
            if(l!=-1){
                l=min(l,i-1);
            }else{
                l=i-1;
            }
            if(!dependence_ache[l-1]){
                dp[i]=dp[i-1]+1;
            }
            dependence_ache[l-1]=false;
        }else if(s[i]=='('){
            if(l==-1){
                if(s[i-1]==':'){
                    l=i;
                    dp[i]=dp[i-1]+1;
                    dependence_ache[i-1]=true;
                }
            }else{
                if(s[l-1]==':' && !dependence_ache[l-1]){
                    dp[i]++;
                    dependence_ache[l-1]=true;
                }
            }
        }
        //debug(l,i,dp[i]);
    }
    ll ans=max(dp[n-1],suff[0]);
    loop(i,1,n-2){
        ans=max(ans,dp[i]+suff[i+1]);
    }
    cout<<ans<<endl;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // ll t;
    // cin>>t;
    // loop(i,1,t+1){
    //     //cout<<"Case "<<i<<": ";
    //     solve();
    //     //cout<<endl;
    // }
    solve();     
}

