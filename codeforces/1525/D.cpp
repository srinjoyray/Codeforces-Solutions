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
#define N 6000
lli dp[N][N];
lli a[N],n,count1=0;
vl v;
lli solve(lli incl,lli idx){
    // deb2(incl,idx);
    if(dp[incl][idx]!=-1){
        return dp[incl][idx];
    }
    lli temp1,temp2;
    if(incl>=count1){
        return 0;
    }
    if(idx==n){
        return 1e12;
    }
    
    if(a[idx]==0){
        temp1=abs(v[incl]-idx)+solve(incl+1,idx+1);
    }
    else if(a[idx]==1){
        temp1=1e12;
    }
    temp2=solve(incl,idx+1);
    // deb2(temp1,temp2);
    dp[incl][idx]=min(temp1,temp2);
    return dp[incl][idx];
}
void solve(){
    int i,j;
    lli ans;
    cin>>n;
    fo(i,n){
        cin>>a[i];
        if(a[i]==1){
            count1++;
            v.pb(i);
        }
    }
    memset(dp,-1,sizeof(dp));
    ans=solve(0,0);
    /*for(i=1;i<=count1;i++){
        for(j=0;j<n;j++){
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
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

