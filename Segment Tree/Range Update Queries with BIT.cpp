// cses link : https://cses.fi/problemset/task/1651/
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

template <class T> struct BIT{
    // A[] has to be 1-indexed
    // create BIT of n elements : BIT<ll> bit(n);
    // MODE A (point-update + prefix/range-sum):
    //   add v to A[idx]:     bit.upd(idx, v);
    //   sum of A[1..idx]:    ll sum1 = bit.query(idx);
    //   sum of A[l..r]:      ll sumLR = bit.query(l, r);
    // MODE B (range-update + point-query):
    //   add v to every A[i] for i in [l..r]: bit.upd(l, r, v);
    //   current A[idx]:      ll Ai = bit.query(idx);
    // Note: Do NOT mix MODE A and MODE B on the same instance—
    // use separate BITs if you need both.
    int n;
    vector<T> t;
    BIT() : n(0) {}
    BIT(int _n) {
        n = _n;
        t.assign(n + 1, 0);
    }

    static int lowbit(int x) {
        return x & -x;
    }

    T query(int i) const {
        T ans = 0;
        for (; i > 0; i -= lowbit(i)) ans += t[i];
        return ans;
    }

    void upd(int i, T val) {
        if (i <= 0) return;
        for (; i <= n; i += lowbit(i)) t[i] += val;
    }

    T query(int l, int r) const {
        if (l > r) return 0;
        return query(r) - query(l - 1);
    }

    void upd(int l, int r, T val) {
        upd(l, val); upd(r + 1, -val);
    }
};

void solve(){
    ll n,q;
    cin>>n>>q;
    inparr(a,n);
    BIT<ll> bit(n);
    loop(i,0,n){
        bit.upd(i+1,i+1,a[i]);
    }
    while(q--){
        ll res,idx1,idx2,val,x,y;
        cin>>res;
        if(res==1){
            cin>>idx1>>idx2>>val;
            bit.upd(idx1,idx2,val);
        }else{
            cin>>x;
            cout<<bit.query(x)<<endl;
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

