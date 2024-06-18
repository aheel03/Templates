#include<bits/stdc++.h>
using namespace std;

typedef long long int            ll;
typedef unsigned long long int   ull;
typedef vector<pair<ll,ll>>      vpll;
typedef vector<ll>               vll;
typedef map<ll,ll>               mll;
typedef pair<ll,ll>              pll;
 
#define loop(i,k,n)              for(ll i=k;i<n;i++)
#define pb                       push_back
#define ft                       first 
#define sc                       second
#define yes                      cout<<"Yes"<<endl
#define no                       cout<<"No"<<endl
#define Yes                      cout<<"YES"<<endl
#define No                       cout<<"NO"<<endl
#define Alice                    cout<<"Alice"<<endl
#define Bob                      cout<<"Bob"<<endl
#define newl                     cout<<"\n"
#define clean                    fflush(stdout)
#define FLOOR(x,y)               (ll(floor(double(x)/y)))
#define CEIL(x,y)                (ll(ceil(double(x)/y)))
#define max3(a,b,c)              max(a,max(b,c))
#define min3(a,b,c)              min(a,min(b,c))
#define all(v)                   v.begin(),v.end()
#define rall(v)                  v.rbegin(),v.rend()
#define Max(v)                   *max_element(v.begin(), v.end())
#define Min(v)                   *min_element(v.begin(), v.end())
#define SORT(a)                  sort(a,a+(sizeof(a)/sizeof(a[0])))
#define inparr(arr,n)            ll arr[n]; loop(i,0,n) cin >> arr[i]
#define inpvec(v,n)              vll v(n); for(auto &i:v) cin >> i
#define prec(ans,n)              cout<< fixed << setprecision(n) << ans << endl
const ll M=998244353;
const ll N=2e5+5;
const ll INF=1e15;

ll segtree[N*4];
ll a[N];
ll sizex=1;

ll func(ll a,ll b){
    return min(a,b);
}

void build(ll n){
    ll val=ll(ceil(log2(n)));
    sizex=(1<<val);
    loop(i,0,2*sizex) segtree[i]=0ll;
}

void update(ll node, ll x){
    segtree[node+sizex]=x;
    /* ll parent=node+sizex;
    while(parent>1){
        parent/=2;
        segtree[parent]=func(segtree[parent*2],segtree[(parent*2)+1]);
    } */
}

/* ll query(ll l, ll r){
    ll ans=INF;
    if(l==r) return segtree[l];
    else if(l&1) return func(segtree[l],query(l+1,r));
    else if(r%2==0) return func(segtree[r],query(l,r-1));
    else return query(l/2,r/2);
} */

void query(ll l,ll r,ll x){
    if(l==r){
        segtree[l]+=x;
        return;
    }
    else if(l&1){
        segtree[l]+=x;
        query(l+1,r,x);
    }else if(r%2==0){
        segtree[r]+=x;
        query(l,r-1,x);
    }
    else{
        query(l/2,r/2,x);
    }
}


int main()
{
    ll n,q;
    cin>>n>>q;
    build(n);
    loop(i,0,n){
        cin>>a[i];
        update(i,a[i]);
    }
    loop(i,0,q){
        ll info;
        cin>>info;
        if(info&1){
            ll a,b,u;
            cin>>a>>b>>u;
            query(sizex+a-1,sizex+b-1,u);
        }else{
            ll k;cin>>k;
            ll node=sizex+k-1;
            ll ans=segtree[node];
            while(node>1){
                node/=2;
                ans+=segtree[node];
            }
            cout<<ans<<endl;
        }
    }
}
