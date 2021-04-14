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

void solve(){
    lli i,j;
    lli n;
    cin>>n;
    lli a[n],freq[100001]={0};
    fo(i,n){
        cin>>a[i];
        freq[a[i]]++;
    }
    lli ans=0;
    lli dp[100001][2],temp1,temp2;
    dp[0][0]=0;
    dp[0][1]=0;
    dp[1][0]=freq[1]; dp[1][1]=0;
    for(i=2;i<100001;i++){
        temp1=max(dp[i-1][0],dp[i-1][1]);
        temp2=max(dp[i-1][1],dp[i-2][0]) + i*freq[i];
        dp[i][0]=temp2;
        dp[i][1]=temp1;
    }
    ans=max(dp[100000][0],dp[100000][1]);
    cout<<ans<<nl;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

