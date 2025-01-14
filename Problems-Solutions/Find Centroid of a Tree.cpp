// problem link : https://cses.fi/problemset/task/2079/
#include <bits/stdc++.h>
using namespace std;

typedef long long int            ll;

#define loop(i,k,n)              for(ll i=k;i<n;i++)
#define f                        first 
#define s                        second
#define Yes                      cout<<"YES"<<endl
#define No                       cout<<"NO"<<endl
#define newl                     cout<<"\n"
#define clean                    fflush(stdout)
#define all(v)                   v.begin(),v.end()
#define inparr(arr,n)            ll arr[n]; loop(i,0,n) cin>>arr[i]
#define inpvec(v,n)              vll v(n); for(auto &i:v) cin>>i

const ll M=1e9+7;
const ll INF=1e15;
const ll N=100;

const ll MAXN=2e5+5;
vector<ll> tree[MAXN];
vector<ll> subtree(MAXN,0ll);
vector<bool> vis(MAXN,false);

void dfs_for_subtree_size(ll node,ll parent=-1){
    subtree[node]=1;
    if(!tree[node].size()) return;
    for(auto child:tree[node]){
        if(child==parent) continue;
        dfs_for_subtree_size(child,node);
        subtree[node]+=subtree[child];
    }
}

ll GetCentroid(ll node, ll parent, ll size){
    for(auto child:tree[node]){
        if(child==parent) continue;
        if(subtree[child]*2>size){
            return GetCentroid(child,node,size);
        }
    }
    return node;
}

void solve(){
    ll n;
    cin>>n;
    loop(i,0,n-1){
        ll a,b;
        cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs_for_subtree_size(1);
    ll cen=GetCentroid(1,-1,n);
    cout<<cen<<endl;
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
