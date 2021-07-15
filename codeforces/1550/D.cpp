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
const int N=1e6+10;

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
ll ncr(ll n, ll r){
    if(r<0 || n<r){
        return 0;
    }
    ll ans,num,denom;
    num=fact[n];
    denom=(fact[r]*fact[n-r])%mod;
    denom=power(denom,mod-2);
    ans=(num*denom)%mod;
    return ans;
}
void solve(){
    int i,j;
    ll n,l,r,ans=0;
    cin>>n>>l>>r;
    ll both,curr,pos,neg,rem;
    both=min((ll)1-l,r-n);
    ans=(ncr(n,n/2)*both)%mod;
    if(n%2==1){
        ans=(ans+(ncr(n,n/2+1)*both))%mod;
    }
    
    curr=both+1;
    ll k=curr,temp;
    // deb(ans);
    while(true){
        pos=max(l+k-1,(ll)0);
        neg=n-min(n,r-k);
        rem=n-(pos+neg);
        if(rem<0){
            break;
        }
        // deb(k);
        // deb2(pos,neg);
        
        temp=n/2-pos;
        // deb2(rem,temp);
        
        ans+=ncr(rem,temp);
        ans%=mod;
        
        if(n%2==1){
            temp++;
            // deb2(rem,temp);
            ans+=ncr(rem,temp);
            ans%=mod;   
            
        }

        k++;
        // deb(ans);
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

