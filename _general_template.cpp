#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long int              ll;
typedef vector<long long int>      vll;
typedef pair<long long,long long>  pll;
typedef long double                lld;
typedef tree<int, null_type, less_equal<int>, 
                  rb_tree_tag, tree_order_statistics_node_update> pbds;

#define loop(i,k,n)                for(ll i=k;i<n;i++)
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
#define MOD                        1000000007
#define MOD1                       998244353
#define INF                        1e18
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
template<class T>void _print(T t){cerr<<t;}
template<class T,class V>void _print(pair<T,V>p){cerr<<"{";_print(p.ft);cerr<<",";_print(p.sc);cerr<<"}";}
template<class T>void _print(const vector<T>&v){cerr<<"[ ";for(T i:v){_print(i);cerr<<" ";}cerr<<"]";}
template<class T>void _print(const set<T>&v){cerr<<"[ ";for(T i:v){_print(i);cerr<<" ";}cerr << "]";}
template<class T>void _print(const multiset<T>&v){cerr<<"[ ";for(T i:v){_print(i);cerr<<" ";}cerr<<"]";}
template<class T,class V>void _print(const map<T,V>&v){cerr<<"[ ";for(auto i:v){_print(i);cerr<<" ";}cerr<<"]";}

const ll N=1e6+20;
const double EPS = 1e-9;

void solve(){

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin>>t;
    loop(i,1,t+1){
        //cout<<"Case "<<i<<": ";
        solve();
        //cout<<endl;
    }
    //solve();     
}

