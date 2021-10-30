#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fo(i,n) for(i=0;i<n;i++)
#define fo2(i,start,end) for(i=start;i<=end;i++)
#define rfo(i,n) for(i=n-1;i>=0;i--)
#define deb(x) cout<<#x<<"="<<x<<endl
#define deb2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
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
ll ncr(ll n, ll r){
    ll num,denom,ans;
    num=fact[n];
    denom=(fact[r]*fact[n-r])%mod;
    denom=power(denom,mod-2);
    ans=(num*denom)%mod;
    return ans;
}
ll dp[600][600],n,x;
ll solve(ll rem,ll lowest){
    // deb2(lowest,rem);
    if(rem==0){
        return 1;
    }
    if(rem==1){
        return 0;
    }
    if(lowest>x){
        return 0;
    }
    
    if(dp[rem][lowest]!=-1){
        return dp[rem][lowest];
    }
    ll choose,exp,range,temp,ans=0;
    // deb2(rem,lowest);
    for(int i=0;i<=rem;i++){
        // deb(i);
        choose=ncr(rem,i);
        range=min(rem-1,x-lowest+1);
        exp=power(range,i);
        temp=(choose*exp)%mod;
        // deb2(choose,range);
        // deb2(rem-i,lowest+rem-1);
        temp=(temp*solve(rem-i,lowest+rem-1))%mod;
        // deb(temp);
        ans+=temp;
        ans%=mod;
    }

    return dp[rem][lowest]=ans;
}
void solve(){
    int i,j,z;
    cin>>n>>x;

    memset(dp,-1,sizeof dp);
    
    cout<<solve(n,1)<<nl;
    // fo2(i,0,2){
    //     fo2(j,0,5){
    //         cout<<dp[i][j]<<" ";
    //     }cout<<nl;
    // }
}

/*
dp[rem][lowest]=ncr(n,i)*pow(rem-1,i)*dp[rem-i][lowest+rem-1]
lowest+rem-2 to lowest
    1   2   3   4   5
0   1   1   1   1   1
1   0   0   0   0   0   
2      

*/
int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t=1;
    // cin>>t;
    fact[0]=1;
    for(int i=1;i<N;i++){
        fact[i]=(fact[i-1]*i)%mod;
    }
    while(t--){
        solve();
    }
    
}

