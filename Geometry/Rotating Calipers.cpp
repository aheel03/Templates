#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long int              ll;
typedef vector<long long int>      vll;
typedef pair<long long int,long long int>  pll;
typedef long double                lld;
typedef double db;
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


void printd(double val,int prec){
    cout<<fixed<<setprecision(prec)<<val<<endl;
}

const ll N=20;
const double EPS = 1e-9;
const ll MOD=MOD2;


#define x real()
#define y imag()
const double PI = acos(-1);
const double eps=1e-8;
typedef long long T;
typedef complex<T> pt;
T sign(double x_){return (x_>eps)-(x_<-eps);}
T dot(pt a,pt b) {return (conj(a)*b).x;}
T cross(pt a,pt b) {return (conj(a)*b).y;}
T NORM(pt a) {return dot(a,a);}
double NORM2(pt a) {return sqrt(dot(a,a));} 
T dist_sq(pt a,pt b) {return norm(a-b);}
double dist(pt a,pt b) {return abs(complex<double>(a.x,a.y)-complex<double>(b.x,b.y));}
double angle_of_elev(pt a,pt b) {return arg(b-a);}
double slope(pt a,pt b) {return tan(arg(b-a));}
double arg(pt p,pt q) {return atan2(cross(p, q), dot(p, q));}
// for polar to cartesian : polar(r,theta)
// for cartesian to polar : pt(abs(p), arg(p))
T cross3(pt a,pt b,pt c) {return cross(b-a,c-a);}
// AB X AC
pt rotate_origin(pt a,double theta){
    return a*pt(polar(1.0,theta));}
int orient(pt a, pt b, pt c) {
    double cr = cross(b - a, c - a);
    return sign(cr); // Returns 1 if > eps, -1 if < -eps, 0 otherwise
}
double angle(pt v, pt w) {
    double cosTheta = (double)dot(v, w) / (NORM2(v) * NORM2(w));
    return acos(max(-1.0, min(1.0, cosTheta)));
}
double rad_to_deg(double r) {return(r*180.0/PI);}
double deg_to_rad(double d) {return(d*PI/180.0);}
// p is in the circle with diameter AB
bool inDisk(pt a,pt b,pt p){return dot(a-p,b-p)<=0;}
bool onSegment(pt a,pt b,pt p){return orient(a,b,p)==0 && inDisk(a,b,p);}

void convex_hull(vector<pt>& a, bool incl_col=0) {
    if (a.size() <= 1) return;
    pt p0 = *min_element(a.begin(),a.end(),[](pt a,pt b){
        return make_pair(a.y,a.x)<make_pair(b.y,b.x);
    });
    sort(a.begin(), a.end(), [&p0](const pt&a,const pt&b){
        int o=orient(p0,a,b);
        if (o==0)
            return (p0.x-a.x)*(p0.x-a.x) + (p0.y-a.y)*(p0.y-a.y)
                < (p0.x-b.x)*(p0.x-b.x) + (p0.y-b.y)*(p0.y-b.y);
        return o > 0; // Fixed: Now sorts in CCW order
    });
    if (incl_col){
        int i=(int)a.size()-1;
        while (i>=0 && orient(p0,a[i],a.back())==0) i--;
        reverse(a.begin()+i+1,a.end());
    }
    auto ccw=[](pt a, pt b, pt c,bool incl_col) {
        int o = orient(a, b, c);
        return o > 0 || (incl_col && o == 0);
    };
    vector<pt> st;
    for (int i = 0; i < (int)a.size(); i++) {
        while (st.size() > 1 && !ccw(st[st.size()-2], st.back(), a[i], incl_col))
            st.pop_back();
        st.push_back(a[i]);
    }
    if (incl_col == false && st.size() == 2 && st[0] == st[1]) st.pop_back();
    a = st;
}

pt perp(pt a) {return pt{-a.y,a.x};}

struct line {
    pt v;T c;
    line(pt v, T c) : v(v), c(c) {}
    line(T a, T b, T c) : v({b, -a}), c(c) {}
    line(pt p, pt q) : v(q - p), c(cross(v, p)) {}
    T side(pt p) const {return cross(v, p) - c;}
    double dist(pt p) const {return fabs(side(p)) / NORM2(v);}
    double sqDist(pt p) const {return (double)side(p) * side(p) / NORM(v);}
    line perp_through(pt p) const {return {p, p + perp(v)};}
    bool cmpProj(pt p, pt q) const {return dot(v, p) < dot(v, q);}
    //use line::intersection()
    static bool intersection(line l1, line l2, pt &out) {
        T d = cross(l1.v, l2.v);
        if (fabs(d) <= eps) return false;
        out = (l2.v * l1.c - l1.v * l2.c) / d;
        return true;
    }
    static bool intersection(line l1, line l2, pt &out,ll &dd) {
        ll d = cross(l1.v, l2.v);
        if (abs(d) == 0) return false;
        out = l2.v * l1.c - l1.v * l2.c;
        dd=d;
        return true;
    }
    void shiftLeft(double d){c += d * NORM2(v);}
    pt proj(pt p) const {return p - perp(v) * side(p) / NORM(v);}
    pt refl(pt p) const {return p - perp(v) * (T)2 * side(p) / NORM(v);}};


ll cross2(pt o, pt a, pt b)
{
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

double max_pair_dist2(vector<pt> &H){
    int m = H.size();
    if (m < 2) return 0;
    if (m == 2) return dist_sq(H[0], H[1]);
    ll best = 0;
    int j = 1;
    double ans=1e9;
    for (int i = 0; i < m; ++i)
    {
        while (abs(cross2(H[i], H[(i + 1) % m], H[(j + 1) % m])) > abs(cross2(H[i], H[(i + 1) % m], H[j])))
        {
            j = (j + 1) % m;
        }
        
        best = max(best, (ll)dist_sq(H[i], H[j]));
        best = max(best, (ll)dist_sq(H[(i + 1) % m], H[j]));
        line ln=line(H[i], H[(i + 1) % m]);
        double cur=ln.dist(H[j]);
        ans=min(ans,cur);
        //debug(i,j,cur);
    }
    return ans;
}

void solve() {
    ll n;
    cin>>n;
    vector<pt> pts;
    loop(i,0,n){
        ll a,b;
        cin>>a>>b;
        pt p=pt(a,b);
        pts.pb(p);
    }
    convex_hull(pts);
    // loop(i,0,n){
    //     cout<<pts[i].x<<" "<<pts[i].y<<endl;
    // }
    //reverse(all(pts));
    double ans=max_pair_dist2(pts);
    cout<<fixed<<setprecision(10)<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // freopen("dome.in","r",stdin);
    // freopen("dome.out","w",stdout);

    ll t=1;
    //cin>>t;
    loop(i,1,t+1){
        //cout<<"Case "<<i<<": ";
        solve();
    }    
}
