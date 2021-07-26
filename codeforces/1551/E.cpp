#include<bits/stdc++.h>
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define fo2(i,start,end) for(i=start;i<=end;i++)
#define rfo(i,n) for(i=n-1;i>=0;i--)
#define ll long long int
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
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
const int N=1e6+10;

void solve(){
    int i,j;
    int n,k;
    cin>>n>>k;
    int a[n+1],b[n+1],val;
    fo2(i,1,n){
        cin>>a[i];
    }
    fo2(i,1,n){
        if(a[i]<i){
            b[i]=-1;
        }
        else{
            b[i]=a[i]-i;
        }
    }

    int dp[n+10][n+10],ans=-1;
    memset(dp,0,sizeof dp);
    fo2(i,1,n){
        for(j=1;j<=i;j++){
            if(a[i]==j){
                val=1;
            }
            else{
                val=0;
            }
            dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]+val);
        }
    }
    for(j=n;j>=1;j--){
        if(dp[n][j]>=k){
            cout<<n-j<<nl;
            return;
        }
    }
    cout<<"-1\n";
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
    
}

