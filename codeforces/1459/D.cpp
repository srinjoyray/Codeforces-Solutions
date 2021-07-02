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
const int N=101;
int dp[N][N][N*101];


void solve(){
    int i,j,k;
    int n;
    cin>>n;
    int a[n],b[n],ans[n+1],sum=0,temp1,temp2;
    fo(i,n){
        cin>>a[i]>>b[i];
        sum+=b[i];
    }
    // deb(sum);
    // dp[Indexupto][no of selection][total_storage]
    memset(dp,-1,sizeof dp);
    fo(i,n){
        fo(j,n+1){
            fo(k,n*101){
                if(j==0 && k==0){
                    dp[i][j][k]=0;
                }
            }
        }
    }
    // dp[0][0][0]=0;
    dp[0][1][a[0]]=b[0];
    fo2(i,1,n-1){
        fo2(j,1,i+1){
            fo2(k,1,n*101){
                // deb2(i,j);
                // deb(k);
                temp1=-1;
                temp2=-1;
                if(k>=a[i] && dp[i-1][j-1][k-a[i]]!=-1){
                    temp1=dp[i-1][j-1][k-a[i]]+b[i];
                }
                temp2=dp[i-1][j][k];
                dp[i][j][k]=max(temp1,temp2);
            }
        }
    }
    double mx,rem,fill,temp;
    // deb(sum);
    // fo(i,n){
    //     fo2(j,1,i+1){
    //         deb2(i,j);
    //         fo(k,23){
    //             cout<<dp[i][j][k]<<" ";
    //         }
    //         cout<<nl;
    //     }
    // }
    fo2(j,1,n){
        mx=0;
        fo(k,n*101){
            if(dp[n-1][j][k]!=-1){
                fill=dp[n-1][j][k];
                rem=sum-fill;
                temp=min((double)k,fill+rem/2);
                mx=max(mx,temp);
            }
        }
        cout<<fixed<<setprecision(10)<<mx<<" ";
    }

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

