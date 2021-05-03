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
lli dp[100001],prefix[100001];
void preset(lli k){
    int i,j;
    fo(i,k){
        dp[i]=1;
    }
    fo2(i,k,100000){
        dp[i]=dp[i-1]+dp[i-k];
        if(dp[i]<0){
            // deb2(i,dp[i]);
        }
        dp[i]%=mod;
    }
    prefix[0]=dp[0];
    for(i=1;i<=100000;i++){
        prefix[i]=prefix[i-1]+dp[i];
        prefix[i]%=mod;
    }
}
void solve(lli k){
    int i,j;
    lli a,b,ans;
    cin>>a>>b;
    // deb2(a,b);
    // deb2(prefix[b],prefix[a]);
    ans=prefix[b]-prefix[a-1];
    while(ans<0){
        ans+=mod;
    }
    cout<<ans<<nl;
    
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    lli t=1,k;
    cin>>t>>k;
    preset(k);
    while(t--){
        solve(k);
    }
    return 0;
}

