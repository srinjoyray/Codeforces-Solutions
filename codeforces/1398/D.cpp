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
int dp[300][300][300],r,g,b;
vi v1,v2,v3;
int func(int i,int j,int k){
    if(dp[i][j][k]!=-1){
        return dp[i][j][k];
    }
    int ans=0,temp;
    
    // deb2(i,j); deb(k);
    if(i<v1.size() && j<v2.size()){
        temp=v1[i]*v2[j]+func(i+1,j+1,k);
        ans=max(ans,temp);
    }
    if(i<v1.size() && k<v3.size()){
        temp=v1[i]*v3[k]+func(i+1,j,k+1);
        ans=max(ans,temp);
    }
    if(k<v3.size() && j<v2.size()){
        temp=v3[k]*v2[j]+func(i,j+1,k+1);
        ans=max(ans,temp);
    }
    
    return dp[i][j][k]=ans;
}
void solve(){
    int i,j;
    int temp=1,ans=0;
    cin>>r>>g>>b;
    fo(i,r){
        cin>>temp;
        v1.pb(temp);
    }
    fo(i,g){
        cin>>temp;
        v2.pb(temp);
    }
    fo(i,b){
        cin>>temp;
        v3.pb(temp);
    }
    sort(all(v1),greater<int>());
    sort(all(v2),greater<int>());
    sort(all(v3),greater<int>());
    memset(dp,-1,sizeof(dp));
    ans=func(0,0,0);

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

