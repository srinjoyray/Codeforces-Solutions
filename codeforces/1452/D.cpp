#include<bits/stdc++.h>
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define fo2(i,start,end) for(i=start;i<=end;i++)
#define rfo(i,n) for(i=n-1;i>=0;i--)
#define lli long long int
#define deb(x) cout<<#x<<"="<<x<<endl
#define deb2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
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
typedef pair<lli, lli>	pl;
typedef vector<int>		vi;
typedef vector<lli>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
lli dp[1000000];
lli power(lli a,lli n){
    lli res=1;
    while(n){
        if(n%2==1){
            res*=a;
            res%=mod;
        }
        a*=a;
        a%=mod;
        n/=2;
    }
    return res%mod;
}
lli func(lli n){
    lli odd_sum=1,even_sum=1;
    lli i,j;
    if(n==1){
        return 1;
    }
    dp[1]=1; dp[0]=1;
    for(i=2;i<=n;i++){
        if(i%2==0){
            dp[i]=odd_sum;
            even_sum+=dp[i];
        }
        else{
            dp[i]=even_sum;
            odd_sum+=dp[i];
        }
        even_sum%=mod;
        odd_sum%=mod;
    }
    return dp[n]%mod;
    /*if(n==0){
        return dp[n]=1;
    }
    if(n==1){
        return dp[n]=1;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    lli j=n-1,temp=0;
    while(j>=0){
        temp+=func(j);
        temp%=mod;
        j-=2;
    }
    return dp[n]=temp;*/
}
void solve(){
    int i,j;
    lli n,temp,denom,num,ans;
    cin>>n;
    memset(dp,-1,sizeof dp);
    num=func(n);
    fo2(i,1,n){
        // deb2(i,dp[i]);
    }
    denom=power(2,n);
    temp=__gcd(num,denom);
    temp=power(temp,mod-2);
    num=(num*temp)%mod;
    denom=(denom*temp)%mod;
    denom=power(denom,mod-2);
    ans=(num*denom)%mod;
    cout<<ans<<nl;
    
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

