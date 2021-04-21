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
bool dp[101][200001];
bool check(lli a[],lli n){
   lli i,j,sum=0,val;
   fo(i,n){
       sum+=a[i];
   }
   if(sum%2==1){
       return false;
   }
   sum/=2;
   fo2(j,0,sum){
       dp[0][j]=false;
   }
   fo2(i,1,n){
       dp[i][0]=true;
   }
   for(i=1;i<=n;i++){
       val=a[i-1];
       for(j=1;j<=sum;j++){
            if(j<val){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=(dp[i-1][j]||dp[i-1][j-val]);
            }
       }
   }
    if(dp[n][sum]==true){
        return true;
    }
    return false;
}
void solve(){
    int i,j;
    int n;
    cin>>n;
    lli a[n],temp,sum=0,pos;
    fo(i,n){
        cin>>a[i];
        sum+=a[i];
    }
    if(!check(a,n)){
        cout<<"0\n";
    }
    else{
        cout<<"1\n";
        while(true){
            pos=-1;
            fo(i,n){
                if(a[i]%2==1){
                    pos=i+1;
                    break;
                }
                a[i]/=2;
            }
            if(pos!=-1){
                break;
            }
        }
        cout<<pos<<nl;
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

