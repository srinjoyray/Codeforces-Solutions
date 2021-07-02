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
    int i,j,k,idx;
    int n,m;
    cin>>n>>m;
    string s[n];
    fo(i,n){
        cin>>s[i];
    }

    fo(i,n){
        fo(j,n){
            if(s[i][j]==s[j][i] && i!=j){
                // deb2(i,j);
                cout<<"YES\n";
                fo(k,m+1){
                    if(k%2==0){
                        cout<<i+1<<" ";
                    }
                    else{
                        cout<<j+1<<" ";
                    }
                }
                cout<<nl;
                return;
            }
        }
    }

    if(m%2==1){
        cout<<"YES\n";
        fo(k,m+1){
            if(k%2==0){
                cout<<"1 ";
            }
            else{
                cout<<"2 ";
            }
        }
        cout<<nl;
        return;
    }

    if(n==2){
        cout<<"NO\n";
        return;
    }
    bool flag1,flag2;
    fo(i,n){
        flag1=false;
        flag2=false;
        fo(j,n){
            if(s[i][j]=='a'){
                flag1=true;
            }
            if(s[i][j]=='b'){
                flag2=true;
            }
        }
        if(flag1 && flag2){
            idx=i;
            break;
        }
    }
    cout<<"YES\n";
    int p=-1,q=-1;
    fo(j,n){
        if(s[idx][j]=='a' && p==-1){
            p=j;
        }
        if(s[idx][j]=='b' && q==-1){
            q=j;
        }
    }
    if(m%4==0){   
        fo(k,m/2){
            if(k%2==0){
                cout<<idx+1<<" ";
            }
            else{
                cout<<p+1<<" ";
            }
        }
        fo(k,m/2){
            if(k%2==0){
                cout<<idx+1<<" ";
            }
            else{
                cout<<q+1<<" ";
            }
        }
        cout<<idx+1<<nl;
    }
    else{
        fo(k,m/2){
            if(k%2==0){
                cout<<p+1<<" ";
            }
            else{
                cout<<idx+1<<" ";
            }
        }
        fo(k,m/2+1){
            if(k%2==0){
                cout<<idx+1<<" ";
            }
            else{
                cout<<q+1<<" ";
            }
        }
        cout<<nl;
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

