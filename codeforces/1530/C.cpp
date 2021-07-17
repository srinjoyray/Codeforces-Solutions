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
    int n;
    cin>>n;
    int a[n],b[n];
    fo(i,n){
        cin>>a[i];
    }
    fo(i,n){
        cin>>b[i];
    }
    int ans=0,rem,sum1=0,sum2=0,sum3=0;
    sort(a,a+n,greater<int>());
    sort(b,b+n,greater<int>());
    multiset<int>  s1,s2,s3;
    rem=n-n/4;
    fo(i,rem){
        sum1+=a[i];
        s1.insert(a[i]);
    }
    fo(i,n){
        if(i<rem){
            s2.insert(b[i]);
            sum2+=b[i];
        }
        else{
            s3.insert(b[i]);
        }
    }
    n++;
    while(sum1<sum2){
        // deb2(sum1,sum2);
        sum1+=100;
        s1.insert(100);
        s3.insert(0);
        if(s3.size()>0){
            s2.insert(*s3.rbegin());
            sum2+=(*s3.rbegin());
            s3.erase(--s3.end());
        }
        
        if(n%4==0){
            sum1-=*s1.begin();
            sum2-=*s2.begin();
            s3.insert(*s2.begin());
            s1.erase(s1.begin());
            s2.erase(s2.begin());
            
        }
        n++;
        ans++;
    }
    cout<<ans<<nl;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    
}

