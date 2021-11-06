#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define fo(i,n) for(i=0;i<n;i++)
#define fo2(i,start,end) for(i=start;i<=end;i++)
#define rfo(i,n) for(i=n-1;i>=0;i--)
#define deb(x) cout<<#x<<"="<<x<<endl
#define deb2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define tr(it,a) for(auto it=a.begin(); it!=a.end();it++)
#define nl '\n'
#define PI 3.1415926535897932384626
#define mod 998244353
 
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
 
const int N=1e6+10;
ll fact[N];
ll power(ll a,ll n){
    ll res=1;
    while(n){
        if(n%2){
            res=(res*a)%mod;
        }
        a=(a*a)%mod;
        n/=2;
    }
    return res;
}
ll find(vl v){
    sort(all(v));
    ll done=0,i,ans=1,temp;
    fo(i,v.size()){
        temp=v[i]-1-done;
        temp=max(temp,(ll)0);
        ans=(ans*temp)%mod;
        done++;
    }
    return ans;
}
void solve(){
    int i,j;
    int n,m;
    cin>>n>>m;
    ll d[n][m],ans=0,denom,reject,temp;
    fo(i,n){
        fo(j,m){
            cin>>d[i][j];
        }
    }
    fo(j,m){
        vl v;
        fo(i,n){
            v.pb(d[i][j]);
        }
        reject=find(v);
        temp=(fact[n]-reject+(ll)10*mod)%mod;
        ans=(ans+temp)%mod;
    }
 
    denom=power(fact[n],mod-2);
 
    ans=(ans*denom)%mod;
 
    cout<<ans<<nl;
    // deb(fact[20]);
}
 
int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t=1;
    // cin>>t;
    fact[0]=1;
    for(int i=1;i<N;i++){
        fact[i]=(fact[i-1]*i)%mod;
    }
    while(t--){
        solve();
    }
    
}
 