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
const int N=1e6+10;
ll fact[N];
ll power(ll a,ll n){
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
ll ncr(ll n,ll r){
    ll ans,num,denom;
    if(r<0 || r>n || n<0){
        return 0;
    }
    num=fact[n];
    denom=(fact[r]*fact[n-r])%mod;
    denom=power(denom,mod-2);
    ans=(num*denom)%mod;
    return ans;
}
void solve(){
    int i,j;
    ll n,m;
    cin>>n>>m;
    ll temp,each=0,ans=0;
    for(i=2;i<=n-1;i++){
        temp=ncr(n-3,i-2);
        each=(each+temp)%mod;
    }
    // deb(each);
    for(i=n-1;i<=m;i++){
        temp=(ncr(i-1,n-2)*(n-2))%mod;
        // deb2(i,temp);
        temp=(temp*each)%mod;
        ans=(ans+temp)%mod;
    }
    cout<<ans<<nl;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t=1;
    // cin>>t;
    fact[0]=fact[1]=1;
    for(int i=2;i<N;i++){
        fact[i]=(fact[i-1]*i)%mod;
    }
    while(t--){
        solve();
    }
    
}

