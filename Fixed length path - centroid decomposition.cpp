// cses link : https://cses.fi/problemset/task/2080
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


vector<ll> tree[N];
vector<ll> subtree_size(N,0ll);
vector<bool> processed_centroid(N,false);
vector<ll> freq;
ll totalpaths=0;
ll maxdepth;
ll n,k;

ll get_subtree_size(ll node, ll parent){
    subtree_size[node]=1;
    for(auto child:tree[node]){
        if(!processed_centroid[child] && child!=parent){
            subtree_size[node]+=get_subtree_size(child,node);
        }
    }
    return subtree_size[node];
}

ll find_centroid(ll node, ll parent, ll compoSize){
    for(auto child:tree[node]){
        if(!processed_centroid[child] && child!=parent && subtree_size[child]>compoSize/2){
            return find_centroid(child,node,compoSize);
        }
    }
    return node;
}

void dfs_count(ll node, ll parent, ll depth){
    if(depth>k) return;
    totalpaths += freq[k-depth];
    maxdepth=max(maxdepth,depth);
    for(auto child:tree[node]){
        if(!processed_centroid[child] && child!=parent){
            dfs_count(child,node,depth+1);
        }
    }
}

void dfs_fill(ll node, ll parent, ll depth){
    if(depth>k) return;
    freq[depth]++;
    for(auto child:tree[node]){
        if(!processed_centroid[child] && child!=parent){
            dfs_fill(child,node,depth+1);
        }
    }
}

void decompose(ll node){
    ll component_size=get_subtree_size(node,-1);
    ll centroid=find_centroid(node,-1,component_size);

    freq[0]=1;
    maxdepth=0;
    processed_centroid[centroid]=true;

    for(auto child:tree[centroid]){
        if(processed_centroid[child]) continue;
        dfs_count(child,centroid,1);
        dfs_fill(child,centroid,1);
    }

    loop(i,0,maxdepth+1) freq[i]=0;

    for(auto child:tree[centroid]){
        if(!processed_centroid[child]) decompose(child);
    }
}




void solve(){
    cin>>n>>k;
    freq.assign(k+1,0ll);
    loop(i,0,n-1){
        ll x,y;
        cin>>x>>y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    decompose(1);
    cout<<totalpaths<<endl;
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
