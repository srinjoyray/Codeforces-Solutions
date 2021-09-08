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
void solve(){
    int i,j;
    int n;
    cin>>n;
    ll a[n],total,ans,minus,count=0,rem,gap,denom,temp;
    fo(i,n){
        cin>>a[i];
    }
    total=fact[n];
    sort(a,a+n,greater<ll>());
    if(a[0]==a[1]){
        cout<<total<<nl;
        return;
    }
    
    fo(i,n){
        if(a[i]==a[0]-1){
            count++;
        }
    }
    if(count==0){
        cout<<"0\n";
        return;
    }
    rem=n-count-1;
    gap=count+2;

    denom=power(fact[count+1],mod-2);
    temp=fact[count+1+rem];
    temp=(temp*denom)%mod;

    minus=(temp*fact[count])%mod;
     
    ans=(total-minus+mod)%mod;

    cout<<ans<<nl;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t=1,i;
    fact[0]=fact[1]=1;
    for(i=2;i<N;i++){
        fact[i]=(fact[i-1]*i)%mod;
    }
    cin>>t;
    while(t--){
        solve();
    }
    
}

