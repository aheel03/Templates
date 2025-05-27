#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

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

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

//const ll M=998244353;
const ll M=1000007;
const ll INF=1e16;
const ll N=1e6+5;
ll maxlcs;

vector<vector<ll>> dp;
vector<vector<ll>> lcs;
string s,t;

set<ll> Sidx[26],Tidx[26];


ll recur(ll x, ll y, ll mxlcs){
    if(dp[x][y]!=-1){
        return dp[x][y];
    }
    ll count=0;
    loop(i,0,26){
        auto it=upper_bound(Sidx[i].begin(),Sidx[i].end(),x);
        if(it==Sidx[i].end()){
            count++;
            continue;
        }
        auto it2=upper_bound(Tidx[i].begin(),Tidx[i].end(),y);
        if(it2==Tidx[i].end()){
            count++;
            continue;
        }

        if(lcs[(*it)-1][(*it2)-1]!=mxlcs){
            count++;
            continue;
        }

        ll temp=recur(*it,*it2,mxlcs-1);
        dp[x][y]+=temp;
        dp[x][y]%=M;
    }

    if(count==26 && mxlcs==0){
        return dp[x][y]=1;
    }else{
        dp[x][y]+=1;
    }
    return dp[x][y];
}

void solve(){
    s.clear();
    t.clear();
    cin>>s;
    cin>>t;
    loop(i,0,26){
        Sidx[i].clear();
        Tidx[i].clear();
    }
    ll n=s.size();
    ll m=t.size();
    ll mx=max<ll>(n,m);
    lcs.assign(mx+1,vector<ll>(mx+1,0ll));
    dp.assign(mx+1,vector<ll>(mx+1,-1ll));
    maxlcs=0;
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if(s[i]==t[j]){
                lcs[i][j]=1+lcs[i+1][j+1];
            }else{
                lcs[i][j]=max(lcs[i][j+1],lcs[i+1][j]);
            }
            maxlcs=max(maxlcs,lcs[i][j]);
        }
    }
    loop(i,0,n){
        Sidx[s[i]-'a'].insert(i+1);
    }
    loop(i,0,m){
        Tidx[t[i]-'a'].insert(i+1);
    }
    ll ans=recur(0,0,maxlcs);
    cout<<dp[0][0]<<endl;
}


 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    ll t;
    cin>>t;
    loop(i,1,t+1){
        cout<<"Case "<<i<<": ";
        solve();
        //cout<<endl;
    }
    // while(t--){
    //    solve();
    // }
    //solve();   
}
