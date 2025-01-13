#include <bits/stdc++.h>
using namespace std;

typedef long long int            ll;

#define loop(i,k,n)              for(ll i=k;i<n;i++)
#define rloop(i,a,b)             for(ll i=a;i>=b;i--)   
#define f                        first 
#define s                        second
#define Yes                      cout<<"YES"<<endl
#define No                       cout<<"NO"<<endl
#define newl                     cout<<"\n"
#define clean                    fflush(stdout)
#define all(v)                   v.begin(),v.end()
#define inparr(arr,n)            ll arr[n]; loop(i,0,n) cin >> arr[i]
#define inpvec(v,n)              vll v(n); for(auto &i:v) cin >> i

const ll M=1e9+7;
const ll INF=1e15;
const ll N=100;


const ll MAXN=3e4+10;
vector<ll> tree[4*MAXN];

void build(ll a[], ll node, ll search_l, ll search_r){
    // root node = 1
    // search_l and search_r is 0-indexed
    if(search_l>=search_r) {
        tree[node]=vector<ll>(1,a[search_l]);
    }else{ 
        ll mid=(search_l+search_r)/2;
        build(a, node*2, search_l, mid);
        build(a, node*2+1, mid+1, search_r);
        merge(tree[node*2].begin(), tree[node*2].end(), 
        tree[node*2+1].begin(), tree[node*2+1].end(), back_inserter(tree[node]));
    }
}

ll VectorsValue(vector<ll>& v, ll k){
    //Here goes the algorithm for the value you want to extract
    ll n=v.size();
    auto it=upper_bound(v.begin(), v.end(), k);
    if(it==v.end()){
        return 0;
    }else{
        ll x=it-v.begin();
        return n-x;
    }
}

ll query(ll node, ll search_l, ll search_r, ll l, ll r, ll val) {
    //initial search_l = 0, search_r = 0, l= 0 indexed left pointer (inclusive)
    //l = 0 indexed left pointer (inclusive)
    //r = 0 indexed right pointer (inclusive)
    if (l>r) return 0;
    if (l==search_l && r==search_r) {
        return VectorsValue(tree[node],val);
    }
    ll mid=(search_l+search_r)/2;
    return query(node*2,search_l,mid,l,min(r,mid),val) + 
           query(node*2+1,mid+1,search_r,max(l,mid+1),r,val);
}


void solve(){
    ll n;
    cin>>n;
    inparr(a,n);
    build(a,1,0,n-1);
    ll q;
    cin>>q;
    ll lastans=0;
    loop(qq,0,q){
        ll a,b,c;
        cin>>a>>b>>c;
        ll i=a^lastans;
        ll j=b^lastans;
        ll k=c^lastans;
        if(i<1)i=1;
        if(j>n)j=n;
        if(i>j){
            lastans=0;
            cout<<lastans<<endl;
            continue;
        }
        lastans=query(1,0,n-1,i-1,j-1,k);
        cout<<lastans<<endl;
    }
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
