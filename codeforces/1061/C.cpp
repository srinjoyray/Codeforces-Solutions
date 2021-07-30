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

vi factors(int num){
    int i;
    vi v;
    // deb(num);
    for(i=1;i*i<=num;i++){
        if(num%i==0){
            v.pb(i);
            if(i*i!=num){
                v.pb(num/i);
            }
        }
    }
    sort(all(v),greater<ll>());
    return v;
}
ll val[N];
void solve(){
    int i,j;
    int n;
    cin>>n;
    // deb(n);
    ll a[n],ans=0;
    fo(i,n){
        cin>>a[i];
    }
    memset(val,0,sizeof val);
    val[0]=1;
    fo(i,n){
        vi v;
        v=factors(a[i]);
        // deb(a[i]);
        fo(j,v.size()){
            // deb(v[j]);
            if(val[v[j]-1]>0){
                ans+=val[v[j]-1];
                ans%=mod;
                val[v[j]]+=val[v[j]-1];
                val[v[j]]%=mod;
            }
        }
        // deb(ans);
    }
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

