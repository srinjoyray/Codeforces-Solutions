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
    int i,j,i1,j1;
    int n;
    cin>>n;
    ll a[n][n],sum=0,diag[n][n];
    fo(i,n){
        fo(j,n){
            cin>>a[i][j];
            sum+=a[i][j];
        }
    }
    if(n==2){
        cout<<sum<<nl;
        cout<<"1 1 1 2\n";
        return;
    }
    
    i=0; j=0;
    while(j<n){
        i1=i;
        j1=j;
        sum=0;
        while(i1<n && j1<n){
            sum+=a[i1][j1];
            i1++; j1++;
        }
        i1=i;
        j1=j;
        while(i1<n && j1<n){
            diag[i1][j1]=sum;
            i1++; j1++;
        }
        j++;
    }
    i=1;j=0;
    while(i<n){
        i1=i;
        j1=j;
        sum=0;
        while(i1<n && j1<n){
            sum+=a[i1][j1];
            i1++; j1++;
        }
        i1=i;
        j1=j;
        while(i1<n && j1<n){
            diag[i1][j1]=sum;
            i1++; j1++;
        }
        i++;
    }

    i=0;j=n-1;
    while(j>=0){
        i1=i;
        j1=j;
        sum=0;
        while(i1<n && j1>=0){
            sum+=a[i1][j1];
            i1++; j1--;
        }
        i1=i;
        j1=j;
        while(i1<n && j1>=0){
            diag[i1][j1]+=sum;
            i1++; j1--;
        }
        j--;
    }

    i=1;j=n-1;
    while(i<n){
        i1=i;
        j1=j;
        sum=0;
        while(i1<n && j1>=0){
            sum+=a[i1][j1];
            i1++; j1--;
        }
        i1=i;
        j1=j;
        while(i1<n && j1>=0){
            diag[i1][j1]+=sum;
            i1++; j1--;
        }
        i++;
    }
    fo(i,n){
        fo(j,n){
            diag[i][j]-=a[i][j];
        }
    }
    // fo(i,n){
    //     fo(j,n){
    //         cout<<diag[i][j]<<" ";
    //     }cout<<nl;
    // }

    ll odd=-1,even=-1,ans;
    pl p1,p2;
    fo(i,n){
        fo(j,n){
            if((i+j)%2==0){
                if(diag[i][j]>even){
                    even=diag[i][j];
                    p2={i+1,j+1};
                }
            }
            else{
                if(diag[i][j]>odd){
                    odd=diag[i][j];
                    p1={i+1,j+1};
                }
            }
        }
    }

    ans=odd+even;
    cout<<ans<<nl;
    cout<<p1.F<<" "<<p1.S<<" "<<p2.F<<" "<<p2.S<<nl;
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

