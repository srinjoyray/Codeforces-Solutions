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
const int N=1000000;
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
    ll num,denom,ans;
    num=fact[n];
    denom=(fact[n-r]*fact[r])%mod;
    denom=power(denom,mod-2);
    ans=(num*denom)%mod;
    return ans;
}
void solve(){
    int i,j;
    int n,m,k;
    cin>>n>>m>>k;
    int a[n],sum=0,freq[n+1]={0},pref[n+1]={0};
    map<int,int> curr;
    fo(i,n){
        cin>>a[i];
    }
   
    sort(a,a+n);
    fo(i,n){
        freq[a[i]]++;
    }
    fo2(i,1,n){
        pref[i]=pref[i-1]+freq[i];
    }
    if(m==1){
        cout<<n<<nl;
        return;
    }
    
    ll count,temp,ans=0,rem,l,r,contd=0;
    
    fo(i,n){
        
        l=a[i];
        r=min(n,a[i]+k);
        temp=pref[r]-pref[l-1]-curr[l];
        
        curr[l]++;
        if(temp<m){
            continue;
        }
        count=ncr(temp-1,m-1);
        ans=(ans+count)%mod;

        
        
    }
    cout<<ans<<nl;

}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t=1;
    cin>>t;
    fact[0]=1;
    fact[1]=1;
    for(int i=2;i<N;i++){
        fact[i]=(fact[i-1]*i)%mod;
    }
    while(t--){
        solve();
    }
}

