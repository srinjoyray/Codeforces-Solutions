#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fo(i,n) for(i=0;i<n;i++)
#define fo2(i,start,end) for(i=start;i<=end;i++)
#define rfo(i,n) for(i=n-1;i>=0;i--)
#define deb(x) cerr<<#x<<"="<<x<<endl
#define deb2(x,y) cerr<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define tr(it,a) for(auto it=a.begin(); it!=a.end();it++)
#define nl '\n'
#define PI 3.1415926535897932384626
#define mod 998244353

typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

const int N=1e6+10;
ll fact[N];
ll power(ll a,ll n){
    ll res=1;
    while(n){
        if(n%2){
            res=(res*a)%mod;
        }
        a=(a*a)%mod;
        n/=2;
    }
    return res;
}
ll ncr(ll n,ll r){
    ll num,denom,ans=1,inv_denom;
    num = fact[n];
    denom = (fact[r]*fact[n-r])%mod;
    inv_denom = power(denom,mod-2);
    ans = (num*inv_denom)%mod;
    return ans;
}
void solve(){
    int i,j;
    int n;
    cin>>n;
    ll a[n];
    fo(i,n){
        cin>>a[i];
    }

    ll dp[n+1]={0},temp,len,sum=0;
    dp[n]=1;

    for(i=n-1;i>=0;i--){
        // deb2(i,a[i]);
        if(a[i]<=0)continue;
        for(j=i+a[i]+1;j<=n;j++){
            len = j-i;
            // deb2(len,a[i]+1);
            temp = ncr(len-1,a[i]);
            // deb2(temp,dp[j]);
            dp[i] = (dp[i] + dp[j]*temp)%mod;
        }
        // deb2(i,dp[i]);
    }

    fo(i,n){
        sum = (sum+dp[i])%mod;
    }
    cout<<sum<<nl;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t=1;
    // cin>>t;
    fact[0] = 1;
    for(int i=1;i<N;i++){
        fact[i] = (fact[i-1]*i)%mod;
    }
    while(t--){
        solve();
    }
    
}

