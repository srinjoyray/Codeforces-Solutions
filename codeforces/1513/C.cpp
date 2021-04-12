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
#define mod 1000000007
typedef pair<int, int>	pii;
typedef pair<lli, lli>	pl;
typedef vector<int>		vi;
typedef vector<lli>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
lli dp[1000000];
void setdp(){
    lli i,j;
    for(i=0;i<10;i++){
        dp[i]=1;
    }
    for(i=10;i<1000000;i++){
        dp[i]=dp[i-9]+dp[i-10];
        dp[i]%=mod;
    }
}
void solve(){
    int i,j;
    lli dig,n,m,ans=0,temp,rem;
    cin>>n>>m;
    temp=n;
    while(temp){
        dig=temp%10;
        temp/=10;
        ans+=dp[dig+m];
        ans%=mod;
    }
    cout<<ans<<nl;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t=1;
    cin>>t;
    setdp();
    while(t--){
        solve();
    }
    return 0;
}

