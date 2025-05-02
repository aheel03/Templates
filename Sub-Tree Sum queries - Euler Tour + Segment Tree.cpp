// cses problem link : https://cses.fi/problemset/task/1137
#include <bits/stdc++.h>
using namespace std;

typedef long long int            ll;

#define loop(i,k,n)              for(ll i=k;i<n;i++)
#define f                        first 
#define s                        second
#define Yes                      cout<<"Yes"<<endl
#define No                       cout<<"No"<<endl
#define newl                     cout<<"\n"
#define clean                    fflush(stdout)
#define all(v)                   v.begin(),v.end()
#define inparr(arr,n)            ll arr[n]; loop(i,0,n) cin>>arr[i]
#define inpvec(v,n)              vector<ll> v(n); for(auto &i:v) cin>>i
#define CEIL(x,y)                (ll(ceil(double(x)/double(y))))

const ll M=998244353;
const ll INF=1e16;
const ll N=2e5+5;


vector<ll> t_in(N,0ll);
vector<ll> t_out(N,0ll);
vector<ll> val(N,0ll);
vector<ll> tree[N];
vector<ll> flattened(N,-1);
vector<ll> pos(N,-1);
vector<ll> values(N,-1);
ll timer=0;
ll n;

ll segtree[N*4];

ll func(ll a,ll b){
    return a+b;
}



void build_segtree(ll node, ll lo, ll hi){
    if(lo==hi){
        segtree[node]=values[lo];
        return;
    }
    ll mid=(lo+hi)/2;
    build_segtree(node*2,lo,mid);
    build_segtree((node*2)+1,mid+1,hi);
    segtree[node]=func(segtree[node*2],segtree[(node*2)+1]);
}

ll query(ll node, ll lo, ll hi, ll l, ll r){
    if(r<lo || l>hi){
        return 0;
        // identity for sum function
    }
    if(l<=lo && r>=hi){
        return segtree[node];
    }
    ll mid=(lo+hi)/2;
    ll left=query(node*2,lo,mid,l,r);
    ll right=query((node*2)+1,mid+1,hi,l,r);
    return func(left,right);
}

void update(ll node, ll lo, ll hi, ll pos, ll u){
    if(lo==hi){
        segtree[node]=u;
        return;
    }
    ll mid=(lo+hi)/2;
    if(pos<=mid){
        update(node*2,lo,mid,pos,u);
    }else{
        update(node*2+1,mid+1,hi,pos,u);
    }

    segtree[node]=func(segtree[node*2],segtree[node*2+1]);
}

void update_tree_value(ll node, ll value){
    update(1,0,n-1,pos[node],value);
}

ll get_subtree_sum(ll node){
    return query(1,0,n-1,t_in[node],t_out[node]);
}


void dfs(ll node, ll parent){

    t_in[node]=timer;
    flattened[timer]=node;
    timer++;

    for(auto child:tree[node]){
        if(child==parent) continue;
        dfs(child,node);
    }
    t_out[node]=timer-1;
}


void solve(){
    ll q;
    cin>>n>>q;
    loop(i,0,n){
        ll x;
        cin>>x;
        val[i+1]=x;
    }
    loop(i,0,n-1){
        ll u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(1,-1);
    loop(i,0,n){
        pos[flattened[i]]=i;
    }
    loop(node,1,n+1){
        values[pos[node]]=val[node];
    }

    build_segtree(1,0,n-1);
    
    while(q--){
        ll res;
        cin>>res;
        if(res==1){
            ll s,x;
            cin>>s>>x;
            update_tree_value(s,x);
        }else{
            ll x;
            cin>>x;
            cout<<get_subtree_sum(x)<<endl;
        }
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
