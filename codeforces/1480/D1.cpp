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
    int n;
    cin>>n;
    int a[n],last1=-1,last2=-1,last,ans=0;
    vi v1,v2;
    fo(i,n){
        cin>>a[i];
    }
    map<int,set<int>> mapp;
    fo(i,n){
        mapp[a[i]].insert(i);
    }    
    fo(i,n){
        if(a[i]==last1){
           v2.pb(a[i]);
           last2=a[i];
        }
        else if(a[i]==last2){
           v1.pb(a[i]);
           last1=a[i];
        }
        else if(v2.size()==0){
            v1.pb(a[i]);
            last1=a[i];
        }
        else{
            if(mapp[v1.back()].upper_bound(i)==mapp[v1.back()].end()){
                v2.pb(a[i]);
                last2=a[i];
            }
            else if(mapp[v2.back()].upper_bound(i)==mapp[v2.back()].end()){
                v1.pb(a[i]);
                last1=a[i];
            }
            else if((*mapp[v1.back()].upper_bound(i))<=(*mapp[v2.back()].upper_bound(i))){
                v1.pb(a[i]);
                last1=a[i];
            }
            else{
                v2.pb(a[i]);
                last2=a[i];
            }
        }
       
    }
    last=-1;
    // fo(i,v1.size()){
    //     cout<<v1[i]<<" ";
    // }cout<<nl;
    // fo(i,v2.size()){
    //     cout<<v2[i]<<" ";
    // }cout<<nl;
    fo(i,v2.size()){
        // deb(v2[i]);
        if(v2[i]!=last){
            ans++;
            last=v2[i];
        }
    }
    // deb(ans);
    last=-1;
    fo(i,v1.size()){
        // deb(v1[i]);
        if(v1[i]!=last){
            ans++;
            last=v1[i];
        }
    }
    // deb(ans);
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

