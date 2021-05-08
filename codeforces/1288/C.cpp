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
lli fact[1000000];
lli power(lli a,lli n){
    lli res=1;
    while(n){
        if(n%2==1){
            res*=a;
            res%=mod;
        }
        a*=a;
        a%=mod;
        n/=2;
    }
    return res;
}
lli ncr(lli n,lli r){
    lli num,denom,ans;
    num=fact[n];
    denom=(fact[r]*fact[n-r])%mod;
    denom=power(denom,mod-2);
    ans=(num*denom)%mod;
    return ans;
}
void solve(){
    int i,j;
    int n,m;
    cin>>n>>m;
    lli ans=0,r=2*m;
    ans=ncr(n+r-1,r);
    cout<<ans<<nl;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t=1;
    // cin>>t;
    lli i;
    fact[0]=1;
    fact[1]=1;
    for(i=2;i<1000000;i++){
        fact[i]=(fact[i-1]*i)%mod;
    }
    while(t--){
        solve();
    }
    return 0;
}

