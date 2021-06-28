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
    int i,j,z;
    int n,k;
    cin>>n>>k;
    string s[n];
    int count=0,ans,temp,row[n]={0},col[n]={0},start,end;
    map<int,pii> rowP,colP;
    fo(i,n){
        cin>>s[i];
    }
    fo(i,n){ 
        temp=0;
        start=0;
        end=0;
        fo(j,n){
            if(s[i][j]=='B'){
                temp++;
                end=j;
                if(temp==1){
                    start=j;
                }
            }
        }
        
        if(temp==0){
            count++;
        }
        else{
            row[i]=temp;
            rowP[i]={start,end};
        }
    }
    // fo(i,n){
    //     cout<<row[i]<<" ";
    // }cout<<nl;

    fo(j,n){
        temp=0;
        start=0;
        end=0;
        fo(i,n){
            if(s[i][j]=='B'){
                temp++;
                end=i;
                if(temp==1){
                    start=i;
                }
            }
        }
        if(temp==0){
            count++;
        }
        else{
            col[j]=temp;
            colP[j]={start,end};
        }
    }

    // fo(i,n){
    //     cout<<col[i]<<" ";
    // }cout<<nl;

    int r[n][n],c[n][n];
   
    memset(r,0,sizeof r);
    memset(c,0,sizeof c);

    fo(i,n){
        if(row[i]==0){
            continue;
        }
        for(j=0;j<n-k+1;j++){
            z=j+k-1;
            if(rowP[i].F>=j && rowP[i].S<=z){
                r[i][j]++;
            }
        }
    }

    fo(j,n){
        if(col[j]==0){
            continue;
        }
        for(i=0;i<n-k+1;i++){
            z=i+k-1;
            if(colP[j].F>=i && colP[j].S<=z){
                c[i][j]++;
            }
        }
    }

    // fo(i,n){
    //     fo(j,n){
    //         cout<<r[i][j]<<" ";
    //     }cout<<nl;
    // }
    // fo(i,n){
    //     fo(j,n){
    //         cout<<c[i][j]<<" ";
    //     }cout<<nl;
    // }

    int prefR[n][n],prefC[n][n];

    memset(prefR,0,sizeof prefR);
    memset(prefC,0,sizeof prefC);

    fo(j,n){
        temp=0;
        fo(i,k){
            temp+=r[i][j];
        }
        prefR[0][j]=temp;
        for(i=1;i<n-k+1;i++){
            z=i+k-1;
            temp+=r[z][j]-r[i-1][j];
            prefR[i][j]=temp;
        }
    }

    // fo(i,n){
    //     fo(j,n){
    //         cout<<prefR[i][j]<<" ";
    //     }cout<<nl;
    // }

    fo(i,n){
        temp=0;
        fo(j,k){
            temp+=c[i][j];
        }
        prefC[i][0]=temp;
        for(j=1;j<n-k+1;j++){
            z=j+k-1;
            temp+=c[i][z]-c[i][j-1];
            prefC[i][j]=temp;
        }
    }

    // fo(i,n){
    //     fo(j,n){
    //         cout<<prefC[i][j]<<" ";
    //     }cout<<nl;
    // }



    // deb(count);

    
    temp=0;
    fo(i,n){
        fo(j,n){
            temp=max(temp,prefR[i][j]+prefC[i][j]);
        }
    }
    ans=count+temp;
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

