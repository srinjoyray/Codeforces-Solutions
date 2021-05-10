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
lli dp[5001][5001];
void solve(){
    int i,j,k,z;
    lli n,m,start,temp,lcs,mx=0;
    cin>>n>>m;
    string a,b;
    cin>>a>>b;
    memset(dp,0,sizeof(dp));
    fo(i,n){
        fo(j,m){
            if(a[i]==b[j]){
                dp[i+1][j+1]=dp[i][j]+=2;
            }   
            else{
                dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j])-1;
                if(dp[i+1][j+1]<0){
                    dp[i+1][j+1]=0;
                }
            }
            mx=max(dp[i+1][j+1],mx);
        }
    }
    /*fo(i,n+1){
        fo(j,m+1){
            cout<<dp[i][j]<<" ";
        }cout<<nl;
    }*/
    cout<<mx<<nl;
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

