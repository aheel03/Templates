// probolem link : https://cses.fi/problemset/task/1687
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
const ll LOG=log2(1e6);

vector<ll> par(MAXN,-1);
vector<ll> depth(MAXN,0);
vector<vector<ll>> anc(MAXN,vector<ll>(LOG,1));

ll kthanc(ll node, ll k){
    if(depth[node]<k){
        return -1;
    }
    loop(i,0,LOG){
        if(k&(1<<i)){
            node=anc[node][i];
        }
    }
    return node;
}

void Buildanc(ll root,ll end_node){
    par[root]=root;
    loop(i,0,LOG){
        loop(node,root,end_node+1){
            if(i==0){
                anc[node][i]=par[node];
                continue;
            }
            if(node!=root) depth[node]=depth[par[node]]+1;
            anc[node][i]=anc[anc[node][i-1]][i-1];
        }
    }
}


void solve(){
    ll n,q;
    cin>>n>>q;
    loop(i,2,n+1){
        ll x;
        cin>>x;
        par[i]=x;
    }
    Buildanc(1,n);
    while(q--){
        ll x,k;
        cin>>x>>k;
        cout<<kthanc(x,k)<<endl;
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
