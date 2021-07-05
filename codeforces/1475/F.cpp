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
bool check(string a[],string b[],int n){
    int i,j,count;
    fo(j,n){
        if(a[0][j]!=b[0][j]){
            fo(i,n){
                if(a[i][j]=='1'){
                    a[i][j]='0';
                }
                else{
                    a[i][j]='1';
                }
            }
        }
    }

    fo(i,n){
        count=0;
        fo(j,n){
            if(a[i][j]!=b[i][j]){
                count++;
            }
        }
        if(count==0 || count==n){
            continue;
        }
        else{
            return false;
        }
    }
    return true;
}
void solve(){
    int i,j;
    int n;
    cin>>n;
    string a[n],b[n],s[n];
    fo(i,n){
        cin>>a[i];
    }
    fo(i,n){
        cin>>b[i];
    }

    fo(i,n){
        s[i]=a[i];
    }
    
    if(check(s,b,n)){
        cout<<"YES\n";
        return;
    }

    fo(i,n){
        s[i]=a[i];
    }
    fo(j,n){
        if(s[0][j]=='0'){
            s[0][j]='1';
        }
        else{
            s[0][j]='0';
        }
    }

    if(check(s,b,n)){
        cout<<"YES\n";
        return;
    }

    cout<<"NO\n";
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
