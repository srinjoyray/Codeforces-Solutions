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
const ll inf=INT64_MAX;
// segment tree for range gcd queries
ll seg[2 * N];
// build the tree (n=size of array)
void build(ll a[],int n) {  
    for(int i=0;i<n;i++){
        seg[n+i]=a[i];
    }
    for (int i=n-1;i>0;--i){
        seg[i] = __gcd(seg[2*i],seg[2*i+1]);
    } 
}


// gcd on interval [l, r) (0 index)
ll query(int l, int r,int n) {  
  ll res = 0;
//   deb2(l,r); deb(n);
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = __gcd(res,seg[l++]);
    if (r&1) res = __gcd(res,seg[--r]);
  }
//   deb(res);
  return res;
}

void solve(){
    int i,j;
    int n;
    cin>>n;
    ll a[n],sz=1,diff[n-1],temp,ans=1,len;
    fo(i,n){
        cin>>a[i];
    }
    if(n==1){
        cout<<"1\n";
        return;
    }
    n--;
    fo(i,n){
        diff[i]=abs(a[i+1]-a[i]);
    }
 
    // fo(i,n){
    //     cout<<diff[i]<<" ";
    // }cout<<nl;
    while(sz<n){
        sz*=2;
    }
    // deb2(sz,n);
    ll b[sz]={0};
    fo(i,n){
        b[i]=diff[i];
    }
    
    // fo(i,sz){
    //     cout<<b[i]<<" ";
    // }cout<<nl;
    build(b,sz);
    // fo(i,4){
    //     cout<<seg[i]<<" ";
    // }cout<<nl;
    i=0; j=0;
    while(j<n && i<n){
        if(i>j){
            j++;
            continue;
        }
        temp=query(i,j+1,sz);
        // deb2(i,j);
        // deb(temp);
        if(temp>1){
            len=j-i+2;
            ans=max(ans,len);
            j++;
        }
        else{
            i++;
        }
    }
    cout<<ans<<nl;
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

