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
    int i,j,x,k;
    lli n,d,m;
    cin>>n>>d>>m;
    
    lli a[n],temp,ans=0,pref[n]={0},total,rem,cum=0;
    vl v1,v2;
    fo(i,n){
        cin>>a[i];
        if(a[i]<=m){
            v1.pb(a[i]);
        }
        else{
            v2.pb(a[i]);
        }
    }
    
    if(n==1){
        cout<<a[0]<<nl;
        return;
    }
    sort(all(v1),greater<lli>());
    sort(all(v2),greater<lli>());
    
    
    n=v1.size(); m=v2.size();
    vl sa(n+1),sb(m+1);
    fo(i,n){
        sa[i+1]=sa[i]+v1[i];
    }
    fo(i,m){
        sb[i+1]=sb[i]+v2[i];
    }
    ans=sa[n];
    for(i=1;i<=m && i+(i-1)*d<=m+n; i++){
        total=i+(i-1)*d;
        rem=m+n-total;
        ans=max(ans,sb[i]+sa[min(n,rem)]);
    }

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

