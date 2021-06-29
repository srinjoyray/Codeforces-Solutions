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
bool check(int a[],int n,int val,int p){
    ll count=1,j,valid;
    fo(j,n){
        valid=n-j-(a[j]-val);
        valid=min(valid,(ll)(n-j));
        valid=max(valid,(ll)0);
        count*=valid;
        count%=p;
        if(count%p==0){
            break;
        }
    }
    if(count%p==0){
        return false;
    }
    return true;
}
void solve(){
    int i,j;
    int n,p;
    cin>>n>>p;
    int a[n],start=0,temp;
    fo(i,n){
        // a[i]=n-i;
        cin>>a[i];
    }
    sort(a,a+n);
    fo(i,n){
        temp=a[i]-i;
        start=max(start,temp);
    }
    // deb(start);
    sort(a,a+n,greater<int>());
    ll count,rem,done,valid;
    vl v;
    ll low,high,mid,end;

    low=start;
    high=1e9+10;
    end=0;
    while(low<=high){
        mid=(low+high)/2;
        if(check(a,n,mid,p)){
            end=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
//    deb2(start,end);
   fo2(i,start,end){
       v.pb(i);
   }

    cout<<v.size()<<nl;
    fo(i,v.size()){
        cout<<v[i]<<" ";
    }cout<<nl;
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

