#include<bits/stdc++.h>
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define fo2(i,start,end) for(i=start;i<=end;i++)
#define rfo(i,n) for(i=n-1;i>=0;i--)
#define lli long long int
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
typedef pair<lli, lli>	pl;
typedef vector<int>		vi;
typedef vector<lli>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
int dp[5001][5001],a[5001],n,k;
int func(int ind,int t){
    if(t==k || ind==n){
        return 0;
    }
    if(dp[ind][t]!=-1){
        return dp[ind][t];
    }
    int j,ans,temp1,temp2;
    j=ind;
    while(j<n && a[j]-a[ind]<=5){
        j++;
    }
    temp1=func(ind+1,t);
    temp2=(j-ind)+func(j,t+1);
    ans=max(temp1,temp2);
    return dp[ind][t]=ans;
}
void solve(){
    int i,j,ans;
    cin>>n>>k;
    fo(i,n){
        cin>>a[i];
    }
    sort(a,a+n);
    memset(dp,-1,sizeof(dp));
    ans=func(0,0);
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
}

