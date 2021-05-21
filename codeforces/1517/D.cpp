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
const int inf=INT_MAX;
void solve(){
    int i,j,z;
    int n,m,k;
    cin>>n>>m>>k;
    int hori[n][m-1];
    fo(i,n){
        fo(j,m-1){
            cin>>hori[i][j];
            // deb(hori[i][j]);
        }
    }
    int vert[n-1][m];
    fo(i,n-1){
        fo(j,m){
            cin>>vert[i][j];
            // deb(vert[i][j]);
        }
    }
    if(k%2==1){
        fo(i,n){
            fo(j,m){
                cout<<"-1 ";
            }cout<<nl;
        }
        return;
    }
    k/=2;
    int dp[n][m][k+1];
   
    fo(i,n){
        fo(j,m){
            dp[i][j][0]=0;
            for(z=1;z<=k;z++){
                dp[i][j][z]=inf;
            }
        }
    }

    for(z=1;z<=k;z++){
        fo(i,n){
            fo(j,m){
                if(i>0){
                    dp[i][j][z]=min(dp[i-1][j][z-1]+vert[i-1][j],dp[i][j][z]);
                    
                }
                if(i<n-1){
                    dp[i][j][z]=min(dp[i+1][j][z-1]+vert[i][j],dp[i][j][z]);
                }
                if(j>0){
                    dp[i][j][z]=min(dp[i][j-1][z-1]+hori[i][j-1],dp[i][j][z]);
                }
                if(j<m-1){
                    dp[i][j][z]=min(dp[i][j+1][z-1]+hori[i][j],dp[i][j][z]);
                }
                // deb(dp[i][j][z]);
            }
        }
    }
    

    fo(i,n){
        fo(j,m){
            cout<<dp[i][j][k]*2<<" ";
        }cout<<nl;
    }
    
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

