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
string to_kbase(int n,int k){
    int binaryNum[32]={0};
    string s;
    int i=0,j;
    while(n>0){
        binaryNum[i] = n % k;
        n=n/k;
        i++;
    }
    fo(j,32){
        s.pb(binaryNum[j]+'0');
    }
    reverse(all(s));
    return s;
}
int to_decimal(string s,int k){
    reverse(all(s));
    int i,ans=0,dig;
    fo(i,32){
        dig=s[i]-'0';
        ans+=pow(k,i)*dig;
    }
    return ans;
}
int xor_plus(int a,int b,int k){
    int ans=0,curr=1,dig,dig1,dig2;
    while(a>0 || b>0){
        dig1=a%k;
        a/=k;
        dig2=b%k;
        b/=k;
        dig=(dig1+dig2)%k;
        ans+=curr*dig;
        curr*=k;
    }
    return ans;
}
int xor_minus(int a,int b,int k){
   int ans=0,curr=1,dig,dig1,dig2;
    while(a>0 || b>0){
        dig1=a%k;
        a/=k;
        dig2=b%k;
        b/=k;
        dig=(dig1-dig2)%k;
        if(dig<0){
            dig+=k;
        }
        ans+=curr*dig;
        curr*=k;
    }
    return ans;
}

void solve(){
    int i,j;
    int n,k;
    cin>>n>>k;
    fflush(stdout);
    int curr=0,input=0,val;
    fo(i,n){
        if(i==0){
            cout<<"0"<<endl;
        }
        else if(i%2==0){
            val=xor_plus(curr,i,k);
            cout<<val<<endl;
            curr=xor_minus(val,curr,k);
        }
        else{
            val=xor_minus(curr,i,k);
            cout<<val<<endl;
            curr=xor_minus(val,curr,k);
        }
        cin>>input;
        if(input==1){
            return;
        }
    }
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

