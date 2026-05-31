#define x real()
#define y imag()
const double PI = acos(-1);
const double eps=1e-9;
typedef double T;
typedef complex<T> pt;
T sign(double x_){return (x_>eps)-(x_<-eps);}
T dot(pt a,pt b) {return (conj(a)*b).x;}
T cross(pt a,pt b) {return (conj(a)*b).y;}
T NORM(pt a) {return dot(a,a);}
double NORM2(pt a) {return sqrt(dot(a,a));} 
T dist_sq(pt a,pt b) {return norm(a-b);}
double dist(pt a,pt b) {return abs(a-b);}
double angle_of_elev(pt a,pt b) {return arg(b-a);}
double slope(pt a,pt b) {return tan(arg(b-a));}
// for polar to cartesian : polar(r,theta)
// for cartesian to polar : pt(abs(p), arg(p))
T cross3(pt a,pt b,pt c) {return cross(a-b,c-b);}
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

pt perp(pt a) {return pt{-a.y,a.x};}
struct line{
    pt v;T c;
    line(pt v,T c):v(v),c(c){}
    line(T a,T b,T c):v({b,-a}),c(c){}
    line(pt p,pt q):v(q-p),c(cross(v,p)){}
    T side(pt p) { return cross(v,p)-c; } // neg = rightside of vector PQ 
    double dist(pt p) { return abs(side(p)) / NORM2(v); } 
    double sqDist(pt p) { return (double)side(p) * side(p) / NORM(v); } 
    line perp_through(pt p) { return {p, p + perp(v)}; }
    bool cmpProj(pt p, pt q) { return dot(v,p) < dot(v,q); }
    bool intersection(line l1, line l2, pt &out) {
        T d = cross(l1.v, l2.v);
        if (d == 0) return false;
        out = (l2.v * l1.c - l1.v * l2.c) / d;
        return true;
    }
    void shiftLeft(double dist);
    
    pt proj(pt p) { return p - perp(v) * side(p) / NORM(v); }
    pt refl(pt p) { return p - perp(v) * 2LL * side(p) / NORM(v); }
};

struct pt3d{
    T X, Y, Z;
    pt3d operator+(pt3d p){return{X+p.X,Y+p.Y,Z+p.Z};}
    pt3d operator-(pt3d p){return{X-p.X,Y-p.Y,Z-p.Z};}
    pt3d operator*(T d){return{X*d,Y*d,Z*d};}
    pt3d operator/(T d){return{X/d,Y/d,Z/d};}
    bool operator==(pt3d p){return tie(X,Y,Z)==tie(p.X,p.Y,p.Z);}
    bool operator!=(pt3d p){return !operator==(p);}
    friend T operator|(pt3d v,pt3d w){return v.X*w.X+v.Y*w.Y+v.Z*w.Z;}
    friend pt3d operator*(pt3d v, pt3d w) {
        return {v.Y*w.Z-v.Z*w.Y,
        v.Z*w.X-v.X*w.Z,
        v.X*w.Y-v.Y*w.X};
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
