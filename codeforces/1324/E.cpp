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
int dp[3000][3000];
int func(int a[],int i,int n,int hr,int h,int l,int r){
    if(i==n){
        return 0;
    }
    if(dp[i][hr]!=-1){
        return dp[i][hr];
    }
    int val1,val2,temp,mx=0;
    val1=(hr+a[i]-1)%h;
    val2=(hr+a[i])%h;
    if(val1>=l && val1<=r){
        temp=1+func(a,i+1,n,val1,h,l,r);
    }
    else{
        temp=func(a,i+1,n,val1,h,l,r);
    }
    mx=max(mx,temp);
    if(val2>=l && val2<=r){
        temp=1+func(a,i+1,n,val2,h,l,r);
    }
    else{
        temp=func(a,i+1,n,val2,h,l,r);
    }
    mx=max(mx,temp);
    return dp[i][hr]=mx;
    
}
void solve(){
    int i,j;
    int n,h,l,r;
    cin>>n>>h>>l>>r;
    int a[n],temp;
    fo(i,n){
        cin>>a[i];
    }
    memset(dp,-1,sizeof dp);
    temp=func(a,0,n,0,h,l,r);
    cout<<temp<<nl;
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
}

