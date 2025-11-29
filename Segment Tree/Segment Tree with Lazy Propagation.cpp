#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long int              ll;
typedef vector<int>      vll;
typedef pair<long long,long long>  pll;
typedef complex<long long int>     point;
typedef complex<double>            pointdb;
typedef tree<int, null_type, less_equal<int>, 
                  rb_tree_tag, tree_order_statistics_node_update> pbds;

#define loop(i,k,n)                for(int i=k;i<n;i++)
#define f                          first 
#define s                          second
#define pb                         push_back
#define yes                        cout<<"Yes"<<endl
#define no                         cout<<"No"<<endl
#define Yes                        cout<<"YES"<<endl
#define No                         cout<<"NO"<<endl
#define newl                       cout<<"\n"
#define clean                      fflush(stdout)
#define all(v)                     v.begin(),v.end()
#define inparr(arr,n)              int arr[n]; loop(i,0,n) cin>>arr[i]
#define inpvec(v,n)                vector<int> v(n); for(auto &i:v) cin>>i
#define CEIL(x,y)                  ((x+y-1)/y)

const int INF=1e16;
const double EPS = 1e-9;
const int M=998244353;

const int N = 5e5 + 9;
int a[N];

struct ST {
  /* * PURPOSE: Segment Tree for Range Sum Query (RSQ) with Range Add Update.
   * * INDEXING: 
   * - 1-based indexing is recommended for consistency (indices 1 to n).
   * - 0-based is possible if you call build(1, 0, n-1), but 'a' array must match.
   * * USAGE EXAMPLES:
   * 1. DEFINITION & BUILD:
   * int n = 5; 
   * for(int i=1; i<=n; i++) a[i] = input[i]; // Fill global array 'a'
   * ST st(n);                                // Initialize vectors
   * st.build(1, 1, n);                       // Build tree from global array 'a'
   * * 2. UPDATE (Range Add):
   * // Add 10 to all elements in range [2, 4]
   * st.upd(1, 1, n, 2, 4, 10);
   * * 3. QUERY (Range Sum):
   * // Get sum of elements in range [2, 4]
   * ll result = st.query(1, 1, n, 2, 4);
   */

  #define lc (n << 1)
  #define rc ((n << 1) | 1)
  vector<ll> t, lazy;
  int N;

  ST(int n = 0) { init(n); }

  void init(int n) {
    N = n;
    t.assign(4 * (N + 5), 0);
    lazy.assign(4 * (N + 5), 0);
  }

  inline void push(int n, int b, int e) {
    if (lazy[n] == 0) return;
    // NOTE: Logic below is for SUM. 
    // For Min/Max, remove *(e-b+1) and just add lazy[n]
    t[n] += lazy[n] * (e - b + 1); 
    if (b != e) {
      lazy[lc] += lazy[n];
      lazy[rc] += lazy[n];
    }
    lazy[n] = 0;
  }

  inline void pull(int n) {
    t[n] = t[lc] + t[rc]; // NOTE: Change to max(t[lc], t[rc]) for RMQ
  }

  void build(int n, int b, int e) {
    lazy[n] = 0;
    if (b == e) { t[n] = a[b]; return; }
    int mid = (b + e) >> 1;
    build(lc, b, mid);
    build(rc, mid + 1, e);
    pull(n);
  }

  void upd(int n, int b, int e, int i, int j, ll v) {
    push(n, b, e);
    if (j < b || e < i) return;            
    if (i <= b && e <= j) {                 
      lazy[n] += v;
      push(n, b, e);
      return;
    }
    int mid = (b + e) >> 1;
    upd(lc, b, mid, i, j, v);
    upd(rc, mid + 1, e, i, j, v);
    pull(n);
  }

  ll query(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if (j < b || e < i) return 0; // NOTE: Return infinity for Min, -infinity for Max
    if (i <= b && e <= j) return t[n];
    int mid = (b + e) >> 1;
    return query(lc, b, mid, i, j) + query(rc, mid + 1, e, i, j);
  }
};

void solve(){
    int n,q;
    cin>>n>>q;
    ST seg(n);
    seg.build(1,1,n);
    while(q--){
        ll res;
        cin>>res;
        if(res==1){
            ll l,r,v;
            cin>>l>>r>>v;
            l++;
            seg.upd(1,1,n,l,r,v);
        }else{
            ll l,r;
            cin>>l>>r;
            l++;
            cout<<seg.query(1,1,n,l,r)<<endl;
        }
    }
}
    




int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    

    // int t;
    // cin>>t;
    // while(t--){
    //    solve();
    // }
    solve();
}
