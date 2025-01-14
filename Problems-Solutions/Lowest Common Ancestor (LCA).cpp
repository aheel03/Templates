// problem link : https://www.spoj.com/problems/LCASQ/
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

ll LCA(ll a,ll b){
    if(depth[a]<depth[b]){
        swap(a,b);
    }
    ll k=depth[a]-depth[b];
    a=kthanc(a,k);
    if(a==b) return a;
    for(ll i=LOG-1;i>=0;i--){
        if(anc[a][i]!=anc[b][i]){
            a=anc[a][i];
            b=anc[b][i];
        }
    }
    return anc[a][0];
}



void solve(){
    ll n;
    cin>>n;
    loop(parent,0,n){
        ll x;
        cin>>x;
        loop(j,0,x){
            ll child;
            cin>>child;
            par[child]=parent;
        }
    }
    ll q;
    cin>>q;
    Buildanc(0,n-1);
    while(q--){
        ll a,b;
        cin>>a>>b;
        cout<<LCA(a,b)<<endl;
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
