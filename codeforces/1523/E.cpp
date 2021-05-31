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
#define mod 1000000007
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
ll fact[1000000];
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
    ll num,denom,ans;
    num=fact[n];
    denom=(fact[r]*fact[n-r])%mod;
    denom=power(denom,mod-2);
    ans=(num*denom)%mod;
    return ans;
}
void solve(){
    int i,j;
    ll n,k,ev=1,num,denom,prob,choose;
    cin>>n>>k;
    for(i=1;i<=n;i++){
        choose=n-(i-1)*(k-1);
        if(i>choose){
            break;
        }
        num=ncr(choose,i);
        denom=ncr(n,i);
        denom=power(denom,mod-2);
        prob=(num*denom)%mod;
        ev=(ev+prob)%mod;
    }
    cout<<ev<<nl;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t=1,i;
    cin>>t;
    fact[0]=1; fact[1]=1;
    for(i=2;i<1000000;i++){
        fact[i]=(fact[i-1]*i)%mod;
    }
    while(t--){
        solve();
    }
}

