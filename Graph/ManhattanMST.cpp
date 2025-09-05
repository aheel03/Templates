// https://judge.yosupo.jp/problem/manhattanmst
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long int              ll;
typedef vector<long long int>      vll;
typedef pair<long long,long long>  pll;
typedef complex<long long int>     point;
typedef complex<double>            pointdb;
typedef tree<int, null_type, less_equal<int>, 
                  rb_tree_tag, tree_order_statistics_node_update> pbds;

#define loop(i,k,n)                for(ll i=k;i<n;i++)
#define f                          first 
#define s                          second
#define yes                        cout<<"Yes"<<endl
#define no                         cout<<"No"<<endl
#define Yes                        cout<<"YES"<<endl
#define No                         cout<<"NO"<<endl
#define newl                       cout<<"\n"
#define clean                      fflush(stdout)
#define all(v)                     v.begin(),v.end()
#define inparr(arr,n)              ll arr[n]; loop(i,0,n) cin>>arr[i]
#define inpvec(v,n)                vector<ll> v(n); for(auto &i:v) cin>>i
#define CEIL(x,y)                  ((x+y-1)/y)

const ll INF=1e16;
const ll N=1e5+5;
const double EPS = 1e-9;
const ll M=998244353;

//Returns {weight of mst, edges of mst} for the set of 2d points
//O(nlogn)
template<typename T, typename C>
pair<C, vector<array<int, 2>>> manhattan_mst_2d(vector<array<T, 2>> m) {
    vector<tuple<T, int, int>> candidates;
    candidates.reserve(m.size() * 4);
    vector<int> id(m.size()); iota(id.begin(), id.end(), 0);
    for (int rot = 0; rot < 4; ++rot) {
        sort(id.begin(), id.end(), [&](const auto& l, const auto& r) {return m[l][0] + m[l][1] < m[r][0] + m[r][1];});
        map<int, int, greater<int>> active;
        for (auto i : id) {
            for (auto it = active.lower_bound(m[i][0]); it != active.end(); active.erase(it++)) {
                int j = it->second;
                if (m[i][0] - m[i][1] > m[j][0] - m[j][1]) break;
                candidates.push_back({abs(m[i][0] - m[j][0]) + abs(m[i][1] - m[j][1]), i, j});
            }
            active[m[i][0]] = i;
        }
        for (auto& p : m) rot & 1 ? void(p[0] *= -1) : swap(p[0], p[1]);
    }
    sort(candidates.begin(), candidates.end());
    vector<int> pr(m.size(), -1);
    function<int(int)> find = [&](int x) {return pr[x] < 0 ? x : pr[x] = find(pr[x]);};
    auto unite = [&](int x, int y) {
        if (x = find(x), y = find(y); x == y) return false;
        if (pr[x] < pr[y]) swap(x, y);
        pr[y] += pr[x], pr[x] = y;
        return true;
    };
    C mst_weight = 0;
    vector<array<int, 2>> mst_edges(m.size() - 1);
    int i = 0;
    for (auto [w, u, v] : candidates) {
        if (unite(u, v)) {
            mst_weight += w;
            mst_edges[i++] = {u, v};
        }
    }

    return {mst_weight, mst_edges};
}


void solve(){
    ll n;
    cin>>n;
    vector<array<ll,2>> pts;
    loop(i,0,n){
        ll xx,yy;
        cin>>xx>>yy;
        pts.push_back({xx,yy});
    }
    auto [total_weight, edges] = manhattan_mst_2d<ll, long long>(pts);
    cout<<total_weight<<endl;
    for(auto [a,b]:edges){
        cout<<a<<" "<<b<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    

    // ll t;
    // cin>>t;
    // while(t--){
    //    solve();
    // }
    solve();
}
