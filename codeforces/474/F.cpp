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
// segment tree for range sum queries
int seg[2 * N];
// build the tree (n=size of array)
void build(int a[],int n) {  
    for(int i=0;i<n;i++){
        seg[n+i]=a[i];
    }
    for (int i=n-1;i>0;--i){
        seg[i] = __gcd(seg[2*i],seg[2*i+1]);
    } 
}
// set value at position p (0 index)
void modify(int p, int val,int n) {  
    p+=n;
    seg[p]=val;
    p/=2;
    while(p>0){
        seg[p]=seg[2*p]+seg[2*p+1];
        p/=2;
    }
}

// sum on interval [l, r) (0 index)
int query(int l, int r,int n) {  
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = __gcd(res,seg[l++]);
    if (r&1) res = __gcd(res,seg[--r]);
  }
  return res;
}
void solve(){
    int i,j;
    int n,temp=1;
    cin>>n;
    while(temp<n){
        temp*=2;
    }
    int a[temp]={0};
    map<int,vi> mapp;
    fo(i,n){
        cin>>a[i];
        mapp[a[i]].pb(i);
    }
    n=temp;
    build(a,n);
    // fo2(i,1,15){
    //     cout<<seg[i]<<" ";
    // }cout<<nl;
    int q;
    cin>>q;
    while(q--){
        int l,r,gcd,ans,count;
        cin>>l>>r;
        l--;
        gcd=query(l,r,n);
        r--;
        ans=r-l+1;
        // deb(gcd);
        if(mapp[gcd].size()==0 || mapp[gcd][0]>r || mapp[gcd].back()<l){
            count=0;
        }
        else{
            vector<int>::iterator right,left;
            right=--upper_bound(mapp[gcd].begin(), mapp[gcd].end(), r);
            left=lower_bound(mapp[gcd].begin(), mapp[gcd].end(), l);
            count=right-left+1;
            // deb(count);
        }
        ans-=count;
        cout<<ans<<nl;
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

