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
int dp[201][401];
int a[201],n;
int solve(int idx,int t){
    if(idx==n){
        return 0;
    }
    if(t>2*n){
        return 1e6;
    }
    if(dp[idx][t]!=-1){
        return dp[idx][t];
    }
    int temp1,temp2,mn;
    temp1=solve(idx,t+1);
    temp2=abs(a[idx]-t)+solve(idx+1,t+1);
    mn=min(temp1,temp2);
    if(idx==3 && t==3){
        // deb2(temp1,temp2);
        // deb(mn);
    }
    // deb2(idx,t);
    // deb(dp[idx][t]);
    return dp[idx][t]=mn;
}
void solve(){
    int i,j;
    cin>>n;
    int ans;
    fo(i,n){
        cin>>a[i];
    }
    sort(a,a+n);
    memset(dp,-1,sizeof(dp));
    
    ans=solve(0,1);
    /*fo(i,n){
        fo(j,n*2){
            cout<<dp[i][j]<<" ";
        }cout<<nl;
    }*/
    cout<<ans<<nl;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

