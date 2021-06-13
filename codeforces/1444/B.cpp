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
#define mod 998244353
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
ll power(ll a, ll n){
    ll res=1;
    while(n){
        if(n%2){
            res=(res*a)%mod;
        }
        a=(a*a)%mod;
        n/=2;
    }
    return res;
}
void solve(){
    int i,j;
    int n;
    cin>>n;
    ll a[2*n],sum=0,ans;
    fo(i,2*n){
        // a[i]=i;
        cin>>a[i];
    }
    sort(a,a+2*n,greater<int>());
    fo(i,2*n){
        if(i<n){
            sum+=a[i];
        }
        else{
            sum-=a[i];
        }
        sum%=mod;
    }
    while(sum<0){
        sum+=mod;
    }
    // deb(sum);
    ll curr=1,p,q,ncr,denom;
    fo2(i,1,2*n){
        curr=(curr*i)%mod;
        if(i==n){
            p=curr;
        }
    }
    q=curr;
    denom=(p*p)%mod;
    denom=power(denom,mod-2);
    ncr=(q*denom)%mod;

    ans=(ncr*sum)%mod;
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

