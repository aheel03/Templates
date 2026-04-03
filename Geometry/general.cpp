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
#define MOD                        1000000007ll
//#define MOD1                       998244353ll
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

const ll N=5e6+20;
const ll MOD1=998244353;


const double eps=1e-9;
int sign(double x){return (x>eps)-(x<-eps);}
typedef long long T;
struct pt{
    T x,y;
    pt(T a,T b):x(a),y(b){}
    pt operator+(pt p) {return {x+p.x,y+p.y};}
    pt operator-(pt p) {return {x-p.x,y-p.y};}
    pt operator*(T d) {return {x*d,y*d};}
    pt operator/(T d) {return {x/d,y/d};}
    bool operator==(pt a) const{return sign(a.x-x)==0 && sign(a.y-y)==0;}
    bool operator!=(pt a) const{return !(*this==a);}
    friend double NORM(pt a){return sqrt((double)(a.x*a.x+a.y*a.y));}
    friend T NORM2(pt a) {return a.x*a.x+a.y*a.y;}
    friend istream& operator>>(istream&in,pt &p){return in>>p.x>>p.y;}
    friend ostream& operator<<(ostream&os,pt p){return os<<"("<<p.x<<","<<p.y<<")";}
    double arg(){return atan2(y,x);}
};
inline T dot(pt a,pt b){return a.x*b.x+a.y*b.y;}
inline T dist2(pt a,pt b){return NORM2(a-b);}
inline double dist(pt a,pt b){return NORM(a-b);}
inline T cross(pt a,pt b){return a.x*b.y-a.y*b.x;}
inline T cross3(pt a,pt b,pt c){return cross(b-a,c-a);}
inline int orient(pt a,pt b,pt c){return sign(cross(b-a,c-a));}
inline double angle(pt v, pt w) {
    double cosTheta = dot(v, w) / NORM(v) / NORM(w);
    return acos(max(-1.0, min(1.0, cosTheta)));
}
inline double rad_to_deg(double r) {return(r*180.0/PI);}
inline double deg_to_rad(double d) {return(d*PI/180.0);}
bool inDisk(pt a,pt b,pt p){return dot(a-p,b-p)<=0;}
// p is in the circle with diameter AB
bool onSegment(pt a,pt b,pt p){return orient(a,b,p)==0 && inDisk(a,b,p);}
double areaPolygon(vector<pt>&p){
    double area=0.0;
    for(int i=0,n=p.size();i<n;i++){
        area+=cross(p[i],p[(i+1)%n]);}
    return abs(area)/2.0;}

bool inPolygon(vector<pt> p, pt a, bool strict = true){
    auto above=[](pt a, pt p){return p.y>=a.y;};
    auto crossesRay=[&](pt a, pt p, pt q) {
        return (above(a,q) - above(a,p)) * orient(a,p,q) > 0;
    };
    int numCrossings = 0;
    for (int i = 0, n = p.size(); i < n; i++){
        if(onSegment(p[i],p[(i+1)%n],a)) return !strict;
        numCrossings += crossesRay(a, p[i], p[(i + 1) % n]);
    }
    return numCrossings & 1;
}

pt perp(pt a) {return pt{-a.y,a.x};}
bool inAngle(pt a,pt b,pt c,pt p){//p lies in the angle <BAC(CW)
    assert(orient(a,b,c)!=0);
    if(orient(a,b,c)<0) swap(b,c);
    return orient(a,b,p)>=0 && orient(a,c,p)<=0;
}
double orientedAngle(pt a,pt b,pt c){//CW BAC
    if(orient(a,b,c)>=0)return angle(b-a,c-a);
    else return 2.0*PI-angle(b-a,c-a);
}
bool isConvex(vector<pt>&p){//collection of points makes a convex hull
    bool hasPos=false,hasNeg=false;
    for (int i=0,n=p.size();i<n;i++){
        int o=orient(p[i],p[(i+1)%n],p[(i+2)%n]);
        if(o>0)hasPos = true;
        if(o<0)hasNeg = true;
    }
    return !(hasPos && hasNeg);
}

struct line{
    pt v;T c;
    line(pt v,T c):v(v),c(c){}
    line(T a,T b,T c):v({b,-a}),c(c){}
    line(pt p,pt q):v(q-p),c(cross(v,p)){}
    T side(pt p) {return cross(v,p)-c;}//neg = rightside of vector PQ 
    double dist(pt p) {return abs(side(p))/NORM(v);}
    double sqDist(pt p) {return side(p)*side(p)/NORM2(v);}
    // line that is perpendicular to this and goes through point p
    line perp_through(pt p) {return{p,p+perp(v)};}
    bool cmpProj(pt p,pt q) {return dot(v,p)<dot(v,q);}
    bool intersection(line l1, line l2, pt &out) {
        T d = cross(l1.v, l2.v);
        if (d == 0) return false;
        out=(l2.v*l1.c-l1.v*l2.c)/d;
        return true;
    }
    void shiftLeft(double dist);
    pt proj(pt p) {return p-perp(v)*side(p)/NORM2(v);}
    pt refl(pt p) {return p-perp(v)*2*side(p)/NORM2(v);}
};

struct pt3d{
    T x, y, z;
    pt3d operator+(pt3d p){return{x+p.x,y+p.y,z+p.z};}
    pt3d operator-(pt3d p){return{x-p.x,y-p.y,z-p.z};}
    pt3d operator*(T d){return{x*d,y*d,z*d};}
    pt3d operator/(T d){return{x/d,y/d,z/d};}
    bool operator==(pt3d p){return tie(x,y,z)==tie(p.x,p.y,p.z);}
    bool operator!=(pt3d p){return !operator==(p);}
    friend T operator|(pt3d v,pt3d w){return v.x*w.x+v.y*w.y+v.z*w.z;}
    friend pt3d operator*(pt3d v, pt3d w) {
        return {v.y*w.z-v.z*w.y,
        v.z*w.x-v.x*w.z,
        v.x*w.y-v.y*w.x};
    }
};
T sq(pt3d v) {return v|v;}
double NORM3(pt3d v) {return sqrt(sq(v));}
pt3d unit(pt3d v) {return v/NORM3(v);}
double angle(pt3d v, pt3d w) {
    double cosTheta=(v|w)/NORM3(v)/NORM3(w);
    return acos(max(-1.0,min(1.0,cosTheta)));
}
T orient(pt3d p,pt3d q,pt3d r,pt3d s){
    return (q-p)*(r-p)|(s-p);}//+ve -> s above pqr


void convex_hull(vector<pt>& a, bool incl_col=0) {
    pt p0 = *min_element(a.begin(),a.end(),[](pt a,pt b){
        return make_pair(a.y,a.x)<make_pair(b.y,b.x);
    });
    sort(a.begin(), a.end(), [&p0](const pt&a,const pt&b){
        int o=orient(p0,a,b);
        if (o==0)
            return (p0.x-a.x)*(p0.x-a.x) + (p0.y-a.y)*(p0.y-a.y)
                < (p0.x-b.x)*(p0.x-b.x) + (p0.y-b.y)*(p0.y-b.y);
        return o < 0;
    });
    if (incl_col){
        int i=(int)a.size()-1;
        while (i>=0 && orient(p0,a[i],a.back())==0) i--;
        reverse(a.begin()+i+1,a.end());
    }
    auto cw=[](pt a, pt b, pt c,bool incl_col) {
        int o = orient(a, b, c);
        return o < 0 || (incl_col && o == 0);
    };
    vector<pt> st;
    for (int i = 0; i < (int)a.size(); i++) {
        while (st.size() > 1 && !cw(st[st.size()-2], st.back(), a[i], incl_col))
            st.pop_back();
        st.push_back(a[i]);
    }
    if (incl_col == false && st.size() == 2 && st[0] == st[1]) st.pop_back();
    a = st;
}

vector<vector<ll>> graph(N,vector<ll>());
vector<bool> vis(N,false);
vector<ll> color(N,-1);

void dfs(ll node,ll par,ll &black,ll &white,bool &thikase){
    debug(node);
    debug(par);
    for(auto child:graph[node]){
        if(color[child]==-1){
            if(color[node]==1){
                color[child]=0;
                white++;
            }
            else{
                color[child]=1;
                black++;
            }
            dfs(child,node,black,white,thikase);
        }else{
            if(color[child]==color[node] && child!=par){
                thikase=false;
                continue;
            }else{
                continue;
            }
        }
    }
}

vector<ll> makepref(vector<ll> &v){
    ll n=v.size();
    vector<ll> pref(n,0ll);
    pref[0]=v[0];
    loop(i,1,n){
        pref[i]=v[i]+pref[i-1];
    }
    return pref;
}

// call FACTMOD() in int main()
vll factmod(N,1ll);

void FACTMOD(){
    loop(i,2,N){
        factmod[i]=(factmod[i-1]*i)%MOD1;
    }
}

ll binpow(ll a, ll n, ll m){
    if(n==0) return 1ll;
    ll x=binpow(a,n/2,m);
    if(n&1){
        return (a*((x*x)%m))%m;
    }else{
        return (x*x)%m;
    }
}

ll nCr(ll n, ll r){
    if(r>n) return 0ll;
    ll nfact=factmod[n];
    ll rfact=binpow(factmod[r],MOD1-2,MOD1);
    ll n_rfact=binpow(factmod[n-r],MOD1-2,MOD1);
    ll ans=(nfact*rfact)%MOD1;
    ans=(ans*n_rfact)%MOD1;
    return ans;
}

void mult(ll&val,ll a,ll b,ll mod){
    a%=mod;
    b%=mod;
    val%=mod;
    val=(val*a)%mod;
    val=(val*b)%mod;
}


void solve()
{
    ll n,m;
    cin>>n>>m;
    inpvec(a,n);
    vll p=makepref(a);
    ll x=0;
    if(p.back()%2==0){
        map<ll,ll> mp;
        loop(i,0,n){
            mp[p[i]]++;
        } 
        loop(i,0,n){
            if(p[i]>p.back()/2){
                break;
            }
            if(mp[p[i]+p.back()/2]!=0){
                x++;
            }
        }
    }
    ll ans=0;
    loop(i,0,x+1){
        ll temp=1;
        mult(temp,factmod[i],nCr(m,i),MOD1);temp%=MOD1;
        mult(temp,binpow(2,x-i,MOD1),binpow(nCr(m-i,2)%MOD1,x-i,MOD1),MOD1);temp%=MOD1;
        mult(temp,binpow(m-i,n-2*x,MOD1),nCr(x,i),MOD1);temp%=MOD1;
        temp%=MOD1;
        ans+=temp;
        ans%=MOD1;
        debug(ans);
    }
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    FACTMOD();

    // ll t;
    // cin>>t;
    // loop(i,1,t+1){
    //     cout<<"Case "<<i<<": ";
    //     solve();
    //     //cout<<endl;
    // }
    solve();     
}

