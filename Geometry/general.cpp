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
double areaPolygon(vector<pt>&p){
    double area=0.0;
    for(int i=0,n=p.size();i<n;i++){
        area+=cross(p[i],p[(i+1)%n]);}
    return abs(area)/2.0;}
//Cutting ray test
bool inPolygon(vector<pt> &p, pt &a, bool strict = true){
    auto above=[](pt aa, pt p){return p.y>=aa.y;};
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
    if(p.size()<3) return false;
    bool hasPos=false,hasNeg=false;
    for (int i=0,n=p.size();i<n;i++){
        int o=orient(p[i],p[(i+1)%n],p[(i+2)%n]);
        if(o>0)hasPos = true;
        if(o<0)hasNeg = true;
    }
    return !(hasPos && hasNeg);
} 

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

struct p3{
    T X, Y, Z;
    p3() : X(0), Y(0), Z(0) {}
    p3(T a,T b,T c):X(a),Y(b),Z(c){}
    p3 operator+(p3 p){return{X+p.X,Y+p.Y,Z+p.Z};}
    p3 operator-(p3 p){return{X-p.X,Y-p.Y,Z-p.Z};}
    p3 operator*(T d){return{X*d,Y*d,Z*d};}
    p3 operator/(T d){return{X/d,Y/d,Z/d};}
    bool operator==(p3 p){return tie(X,Y,Z)==tie(p.X,p.Y,p.Z);}
    bool operator!=(p3 p){return !operator==(p);}
    friend istream& operator>>(istream&in,p3 &p){
        return in>>p.X>>p.Y>>p.Z;
    }
    friend ostream& operator<<(ostream&os,p3 p){
        return os<<"("<<p.X<<","<<p.Y<<","<<p.Z<<")";
    }
    friend T operator|(p3 v,p3 w){
        return v.X*w.X+v.Y*w.Y+v.Z*w.Z;
    }
    friend p3 operator*(p3 v, p3 w) {
        return {
            v.Y*w.Z-v.Z*w.Y,
            v.Z*w.X-v.X*w.Z,
            v.X*w.Y-v.Y*w.X
        };
    }
};
bool eq(double a, double b = 0.0) {
    return fabs(a - b) <= eps;
}
T sq(p3 v) {return v|v;}
double abs(p3 v) {return sqrt(sq(v));}
p3 unit(p3 v) {return v/abs(v);}
bool isZero(p3 v) {return abs(v) <= eps;}
double angle(p3 v, p3 w) {
    double cosTheta=(v|w)/abs(v)/abs(w);
    return acos(max(-1.0,min(1.0,cosTheta)));
}
T orient(p3 p,p3 q,p3 r,p3 s){
    return (q-p)*(r-p)|(s-p);
}//+ve -> s above pqr
T orientByNormal(p3 p, p3 q, p3 r, p3 n) {
    return (q-p)*(r-p)|n;
}

struct plane {
    p3 n; T d;
    // From normal n and offset d
    plane(p3 n, T d) : n(n), d(d) {}
    // From normal n and point P
    plane(p3 n, p3 p) : n(n), d(n|p) {}
    // From three non-collinear points P,Q,R
    plane(p3 p, p3 q, p3 r) : plane((q-p)*(r-p), p) {}
    // Will be defined later:
    // - these work with T = int
    T side(p3 p) {return (n|p)-d;}

    double dist(p3 p) {return abs(side(p))/abs(n);}

    plane translate(p3 t) {return {n, d+(n|t)};}

    // - these require T = double
    plane shiftUp(double dist) {return {n, d + dist*abs(n)};}
    p3 proj(p3 p) {return p - n*side(p)/sq(n);}
    p3 refl(p3 p) {return p - n*2*side(p)/sq(n);}
};

struct line3d {
    p3 d, o;
    line3d(p3 p, p3 q) : d(q-p), o(p) {}
    // From two planes p1, p2 (requires T = double)
    line3d(plane p1, plane p2) {
        d = p1.n*p2.n;
        o = (p2.n*p1.d - p1.n*p2.d)*d/sq(d);
    }
    double sqDist(p3 p) {return sq(d*(p-o))/sq(d);}
    double dist(p3 p) {return sqrt(sqDist(p));}

    bool cmpProj(p3 p, p3 q) {return (d|p) < (d|q);}
    // - these require T = double
    p3 proj(p3 p) {return o + d*(d|(p-o))/sq(d);}

    p3 refl(p3 p) {return proj(p)*2 - p;}
    p3 inter(plane p) {return o - d*p.side(o)/(p.n|d);}

};

p3 zero{0,0,0};
double dist(line3d l1, line3d l2) {
    p3 n = l1.d*l2.d;
    if (n == zero) // parallel
    return l1.dist(l2.o);
    return abs((l2.o-l1.o)|n)/abs(n);
}

double smallAngle(p3 v, p3 w) {
    return acos(min(abs(v|w)/abs(v)/abs(w), 1.0));
}
double angle(plane p1, plane p2) {
    return smallAngle(p1.n, p2.n);
}

bool isParallel(plane p1, plane p2) {
    return p1.n*p2.n == zero;
}
bool isPerpendicular(plane p1, plane p2) {
    return (p1.n|p2.n) == 0;
}

double angle(line3d l1, line3d l2) {
    return smallAngle(l1.d, l2.d);
}
bool isParallel(line3d l1, line3d l2) {
    return l1.d*l2.d == zero;
}
bool isPerpendicular(line3d l1, line3d l2) {
    return (l1.d|l2.d) == 0;
}

double angle(plane p, line3d l) {
    return M_PI/2 - smallAngle(p.n, l.d);
}
bool isParallel(plane p, line3d l) {
    return (p.n|l.d) == 0;
}
bool isPerpendicular(plane p, line3d l) {
    return p.n*l.d == zero;
}

// centroid of a (possibly non-convex) polygon, 
// assuming that the coordinates are listed in a clockwise or
// counterclockwise fashion.  Note that the centroid is often known as
// the "center of gravity" or "center of mass".
pt centroid(vector<pt> &p) {
    int n = p.size(); pt c(0, 0);
    double sum = 0;
    for (int i = 0; i < n; i++) sum += cross(p[i], p[(i + 1) % n]);
    double scale = 3.0 * sum;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        c = c + (p[i] + p[j]) * cross(p[i], p[j]);
    }
    return c / (T)scale;
}

line3d perpThrough(plane p, p3 o) {return line3d(o, (p3)(o+p.n));}
plane perpThrough(line3d l, p3 o) {return plane(l.d, o);}
//POlygon surface area
p3 vectorArea2(vector<p3> p){ 
    // vector area * 2 (to avoid divisions)
    p3 S = zero;
    for (int i = 0, n = p.size(); i < n; i++)
        S = S + p[i] * p[(i + 1) % n];
    return S;
}
double area(vector<p3> p){
    return abs(vectorArea2(p)) / 2.0;
}

double volume(vector<vector<p3>> fs) {
    double vol6 = 0.0;
    for (vector<p3> f : fs)
        vol6 += (vectorArea2(f)|f[0]);
    return abs(vol6) / 6.0;
}


// calculates the area of the union of n polygons (not necessarily convex). 
// the points within each polygon must be given in CCW order.
// complexity: O(N^2), where N is the total number of points
double rat(pt a, pt b, pt p) {
    return !sign(a.x - b.x) ? 
    (p.y - a.y) / (b.y - a.y) : 
    (p.x - a.x) / (b.x - a.x);
};
double polygon_union(vector<vector<pt>> &p) {
	int n = p.size();
    double ans=0;
    for(int i = 0; i < n; ++i) {
        for (int v = 0; v < (int)p[i].size(); ++v) {
            pt a = p[i][v], b = p[i][(v + 1) % p[i].size()];
            vector<pair<double, int>> segs;
            segs.emplace_back(0,  0), segs.emplace_back(1,  0);
            for(int j = 0; j < n; ++j) {
            	if(i != j) {
                    for(size_t u = 0; u < p[j].size(); ++u) {
                        pt c = p[j][u], d = p[j][(u + 1) % p[j].size()];
                        int sc = sign(cross(b - a, c - a)), sd = sign(cross(b - a, d - a));
                        if(!sc && !sd) {
                            if(sign(dot(b - a, d - c)) > 0 && i > j) {
                                segs.emplace_back(rat(a, b, c), 1), segs.emplace_back(rat(a, b, d),  -1);
                            }
                        } 
                        else {
                            double sa = cross(d - c, a - c), sb = cross(d - c, b - c);
                            if(sc >= 0 && sd < 0) segs.emplace_back(sa / (sa - sb), 1);
                            else if(sc < 0 && sd >= 0) segs.emplace_back(sa / (sa - sb),  -1);
                        }
                    }
                }
            }
            sort(segs.begin(),  segs.end());
            double pre = min(max(segs[0].first, 0.0), 1.0), now, sum = 0;
            int cnt = segs[0].second;
            for(int j = 1; j < segs.size(); ++j) {
                now = min(max(segs[j].first, 0.0), 1.0);
                if (!cnt) sum += now - pre;
                cnt += segs[j].second;
                pre = now;
            }
            ans += cross(a, b) * sum;
        }
    }
    return ans * 0.5;
}
// contains all points p such that: cross(b - a, p - a) >= 0
struct HP {
    pt a, b;
    HP() {}
    HP(pt a, pt b) : a(a), b(b) {}
    HP(const HP& rhs) : a(rhs.a), b(rhs.b) {}
    int operator < (const HP& rhs) const {
        pt p = b - a;
        pt q = rhs.b - rhs.a;
        int fp = (p.y < 0 || (p.y == 0 && p.x < 0));
        int fq = (q.y < 0 || (q.y == 0 && q.x < 0));
        if (fp != fq) return fp == 0;
        if (cross(p, q)) return cross(p, q) > 0;
        return cross(p, rhs.b - a) < 0;
    }
    pt line_line_intersection(pt a, pt b, pt c, pt d) {
        b = b - a; d = c - d; c = c - a;
        return a + b * cross(c, d) / cross(b, d);
    }
    pt intersection(const HP &v) {
        return line_line_intersection(a, b, v.a, v.b);
    }
};
int check(HP a, HP b, HP c) {
    return cross(a.b - a.a, b.intersection(c) - a.a) > -eps; 
    //-eps to include polygons of zero area (straight lines, points)
}
// consider half-plane of counter-clockwise side of each line
// if lines are not bounded add infinity rectangle
// returns a convex polygon, a point can occur multiple times though
// complexity: O(n log(n))
vector<pt> half_plane_intersection(vector<HP> h) {
    sort(h.begin(), h.end());
    vector<HP> tmp;
    for (int i = 0; i < h.size(); i++) {
        if (!i || cross(h[i].b - h[i].a, h[i - 1].b - h[i - 1].a)) {
            tmp.push_back(h[i]);
        }
    }
    h = tmp;
    vector<HP> q(h.size() + 10);
    int qh = 0, qe = 0;
    for (int i = 0; i < h.size(); i++) {
        while (qe - qh > 1 && !check(h[i], q[qe - 2], q[qe - 1])) qe--;
        while (qe - qh > 1 && !check(h[i], q[qh], q[qh + 1])) qh++;
        q[qe++] = h[i];
    }
    while (qe - qh > 2 && !check(q[qh], q[qe - 2], q[qe - 1])) qe--;
    while (qe - qh > 2 && !check(q[qe - 1], q[qh], q[qh + 1])) qh++;
    vector<HP> res; 
    for (int i = qh; i < qe; i++) res.push_back(q[i]);
    vector<pt> hull;
    if (res.size() > 2) {
        for (int i = 0; i < res.size(); i++) {
             hull.push_back(res[i].intersection(res[(i + 1) % ((int)res.size())]));
        }
    }
    return hull;
}
// rotate the polygon such that the (bottom, left)-most point is at the first position
void reorder_polygon(vector<pt> &p) {
    int pos = 0;
    for (int i = 1; i < p.size(); i++) {
        if (p[i].y < p[pos].y || (sign(p[i].y - p[pos].y) == 0 && p[i].x < p[pos].x)) pos = i;
    }
    rotate(p.begin(), p.begin() + pos, p.end());
}
// a and b are convex polygons
// returns a convex hull of their minkowski sum
// min(a.size(), b.size()) >= 2
// https://cp-algorithms.com/geometry/minkowski.html
vector<pt> minkowski_sum(vector<pt> a, vector<pt> b) {
    reorder_polygon(a); reorder_polygon(b);
    int n = a.size(), m = b.size();
    int i = 0, j = 0;
    a.push_back(a[0]); a.push_back(a[1]);
    b.push_back(b[0]); b.push_back(b[1]);
    vector<pt> c;
    while (i < n || j < m) {
        c.push_back(a[i] + b[j]);
        double p = cross(a[i + 1] - a[i], b[j + 1] - b[j]);
        if (sign(p) >= 0) ++i;
        if (sign(p) <= 0) ++j;
    }
    return c;
}

vector<pt> seq;
pt translation;
int n;
//int sgn(long long val) { return val > 0 ? 1 : (val == 0 ? 0 : -1); }
bool lexComp(const pt &l, const pt &r) {
    if (sign(l.x - r.x) != 0)
        return l.x < r.x;
    return l.y < r.y;
}

bool pointInTriangle(pt a, pt b, pt c, pt point) {
    T s1 = abs(cross3(a, b, c));
    T s2 = abs(cross3(point, a, b)) + abs(cross3(point, b, c)) + abs(cross3(point, c, a));
    return sign(s1 - s2) == 0;
}

void prepare(vector<pt> &points) {
    n = points.size();
    int pos = 0;
    for (int i = 1; i < n; i++) {
        if (lexComp(points[i], points[pos])) pos = i;
    }
    rotate(points.begin(), points.begin() + pos, points.end());

    n--;
    seq.resize(n);
    for (int i = 0; i < n; i++)
        seq[i] = points[i + 1] - points[0];
    translation = points[0];
}
//fast convex hull point detection queries
bool pointInConvexPolygon(pt point) {
    point = point - translation;
    if (sign(cross(seq[0], point)) != 0 &&
            sign(cross(seq[0], point)) != sign(cross(seq[0], seq[n - 1])))
        return false;
    if (sign(cross(seq[n - 1], point)) != 0 &&
            sign(cross(seq[n - 1], point)) != sign(cross(seq[n - 1], seq[0])))
        return false;

    if (sign(cross(seq[0], point)) == 0)
        return NORM(seq[0]) >= NORM(point);

    int l = 0, r = n - 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        int pos = mid;
        if (sign(cross(seq[pos], point)) >= 0)
            l = mid;
        else
            r = mid;
    }
    int pos = l;
    return pointInTriangle(seq[pos], seq[pos + 1], pt(0, 0), point);
}

//circle and polygon intersection area
double circlePoly(pt c, double r, const vector<pt>& ps) {
    auto tri = [&](pt p, pt q) {
        auto r2 = r * r / 2.0;
        pt d = q - p;
        if (NORM(d) < eps) return 0.0; // Guard against zero-length edges
        auto a = dot(d, p) / NORM(d);
        auto b = (NORM(p) - r * r) / NORM(d);
        auto det = a * a - b;
        if (det <= 0) return arg(p,q) * r2;
        auto s = max(0.0, -a - sqrt(det));
        auto t = min(1.0, -a + sqrt(det));
        if (t < 0 || 1 <= s) return arg(p,q) * r2;
        pt u = p + d * ((T)s);
        pt v = p + d * ((T)t);
        return arg(p,u) * r2 + cross(u, v) / 2.0 + arg(v,q) * r2;
    };
    double sum = 0.0;
    for (int i = 0; i < sz(ps); i++) {
        sum += tri(ps[i] - c, ps[(i + 1) % sz(ps)] - c);
    }
    return sum;
}

//segment-point distance
double segPoint(pt a, pt b, pt p){
    if (a != b){
        line l(a, b);
        if (l.cmpProj(a,p) && l.cmpProj(p,b)) return l.dist(p);
    }
    return min(abs(p-a),abs(p-b));
}
// segment-segment proper intersection
bool properInter(pt a, pt b, pt c, pt d, pt &out){
    double oa = orient(c, d, a),
           ob = orient(c, d, b),
           oc = orient(a, b, c),
           od = orient(a, b, d);
    if (oa*ob<0 && oc*od<0){
        // ** caution!!!
        out = (a*(T)ob-b*(T)oa)/(T)(ob-oa); 
        return true;
    }
    return false;
}
//segment-segment distance
double segSeg(pt a, pt b, pt c, pt d){
    pt dummy;
    if (properInter(a, b, c, d, dummy)) return 0;
    return min({segPoint(a, b, c), segPoint(a, b, d),
                segPoint(c, d, a), segPoint(c, d, b)});
}

//slope between two points
pair<ll,ll> gib_slope(pt A,pt B){
    ll up=A.y-B.y;
    ll down=A.x-B.x;
    ll g=__gcd(abs(up),abs(down));
    if(down<0){
        up*=-1;
        down*=-1;
    }
    return make_pair(up/g,down/g);
}

bool in_rect(ll L,ll W,pt p){
    if(p.x<L && p.x>0 && p.y<W && p.y>0) return true;
    else return false;
}

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

ll longestIncreasingSubsequence(vector<ll>& nums) {
    vector<ll> temp;
    for (ll num : nums) {
        auto it = lower_bound(temp.begin(), temp.end(), num);
        if (it == temp.end()) temp.push_back(num);
        else *it = num;
    }
    return temp.size();
}

void solve() {
    ll ox,oy;
    cin>>ox>>oy;
    ll n;
    cin>>n;
    vector<pt> pts;
    vll hs;
    map<pair<ll,ll>,vector<ll>> m_pos;
    map<pair<ll,ll>,vector<ll>> m_neg;
    loop(i,0,n){
        ll xx,yy,h;
        cin>>xx>>yy>>h;
        pts.push_back(pt(xx-ox,yy-oy));
        hs.push_back(h);
    }
    loop(i,0,n){
        if(pts[i].x>0){
            ll g=__gcd(abs(pts[i].x),abs(pts[i].y));
            m_pos[make_pair(pts[i].x/g,pts[i].y/g)].push_back(hs[i]);
        }else{
            ll g=__gcd(abs(pts[i].x),abs(pts[i].y));
            m_neg[make_pair(pts[i].x/g,pts[i].y/g)].push_back(hs[i]);
        }
        //cout<<"("<<pts[i].x<<","<<pts[i].y<<")"<<" , "<<hs[i]<<endl;
    }

    ll ans=0;
    for(auto &[pr,vec]:m_pos){
        ll prev=0;
        ll cnt=0;
        cnt=longestIncreasingSubsequence(vec);
        ans+=cnt;
    }
    for(auto &[pr,vec]:m_neg){
        ll prev=0;
        ll cnt=0;
        cnt=longestIncreasingSubsequence(vec);
        ans+=cnt;
    }
    cout<<ans<<endl;
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
