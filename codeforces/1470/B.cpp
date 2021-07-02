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

int spf[N];
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
}

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
    int a[n],temp,count,sp;
    fo(i,n){
        cin>>a[i];
        // deb(a[i]);
    }
    
    fo(i,n){
        temp=1;
        while(a[i]>1){
            // deb(a[i]);
            count=0;
            sp=spf[a[i]];
            while(a[i]%sp==0){
                count++;
                a[i]/=sp;
            }
            count%=2;
            temp*=pow(sp,count);
        }
        temp*=a[i];
        // deb(temp);
        a[i]=temp;
    }
    // fo(i,n){
    //     cout<<a[i]<<" ";
    // }cout<<nl;

    map<int,int> freq,sec;
    int ans1=0,ans2=0;
    fo(i,n){
        freq[a[i]]++;
        ans1=max(ans1,freq[a[i]]);
    }

    fo(i,n){
        if(freq[a[i]]%2==0){
            a[i]=1;
        }
    }

    fo(i,n){
        sec[a[i]]++;
        ans2=max(ans2,sec[a[i]]);
    }

    int q;
    cin>>q;
    while(q--){
        ll w;
        cin>>w;
        if(w==0){
            cout<<ans1<<nl;
        }
        else{
            cout<<ans2<<nl;
        }
    }


}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t=1;
    cin>>t;
    sieve();
    while(t--){
        solve();
    }
}

