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

void solve(){
    int i,j;
    int n;
    cin>>n;
    ll x[n],y[n],s[n];  
    fo(i,n){
        cin>>x[i]>>y[i]>>s[i];
    }
    ll a[n]={0},carry=0,sum=0,ans=0;
    ans=(x[n-1]+1)%mod;
    set<pl> se;
    
    for(i=n-1;i>=0;i--){
        // deb(carry);
        
        while(se.size()>0 && (*se.rbegin()).F>x[i]){
            sum-=(*se.rbegin()).S;
            se.erase(--se.end());
        }
        while(sum<0){
            sum+=mod;
        }
        carry=sum;
        if(s[i]==1){
            carry++;
        }
        carry%=mod;
        se.insert({y[i],carry});
        a[i]=carry;
        sum+=carry;
        sum%=mod;
        // deb2(carry,sum);
    }

    // fo(i,n){
    //     cout<<a[i]<<" ";
    // }cout<<nl;

    // deb(ans);
    fo(i,n){
        ans+=(a[i]*(x[i]-y[i]))%mod;
        ans%=mod;
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

