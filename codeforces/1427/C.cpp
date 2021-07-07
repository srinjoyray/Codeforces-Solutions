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
const int N=1e6;

/*bool prime[N + 1];
void sieveOfEratosthenes()
{
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= N; p++)
    {
        if (prime[p] == true){
            for (int i = p * p; i <= N; i += p)
                prime[i] = false;
        }
    }
    prime[0]=false; prime[1]=false;
}*/

/*int spf[N];
void sieve()
{
    spf[1] = 1;
    for (int i=2; i<N; i++)
        spf[i] = i;

    for (int i=4; i<N; i+=2)
        spf[i] = 2;
 
    for (int i=3; i*i<N; i++){
        if (spf[i] == i){
            for (int j=i*i; j<N; j+=i)
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}*/

/*string to_binary(int n){
    int binaryNum[32]={0};
    string s;
    int i=0,j;
    while(n>0){
        binaryNum[i] = n % 2;
        n=n/2;
        i++;
    }
    fo(j,32){
        s.pb(binaryNum[j]+'0');
    }
    reverse(all(s));
    return s;
}*/

/*ll power(ll a,ll n){
    ll res=1;
    while(n){
        if(n%2){
            res=(res*a)%mod;
        }
        a=(a*a)%mod;
        n/=2;
    }
    return res;
}*/

void solve(){
    int i,j;
    int r,n;
    cin>>r>>n;
    int t[n+1],x[n+1],y[n+1];
    t[0]=0; x[0]=1; y[0]=1;
    fo2(i,1,n){
        cin>>t[i]>>x[i]>>y[i];
    }

    int dp[n+1]={0},pref[n+1]={0},mx,temp;
    for(i=1;i<=n;i++){
        mx=0;
        for(j=i-1;j>=0;j--){
            if(t[i]-t[j]>=2*r){
                mx=max(mx,pref[j]+1);
                break;
            }
            temp=abs(x[j]-x[i])+abs(y[j]-y[i]);
            if(temp<=t[i]-t[j]){
                // deb(temp);
                // deb2(i,j);
                if(dp[j]==0 && j>0){
                    continue;
                }
                mx=max(mx,dp[j]+1);
            }
        }
        dp[i]=mx;
        pref[i]=max(pref[i-1],dp[i]);
    }
    // fo2(i,0,n){
    //     cout<<dp[i]<<" ";
    // }cout<<nl;
    // fo2(i,0,n){
    //     cout<<pref[i]<<" ";
    // }cout<<nl;
    cout<<pref[n]<<nl;
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

