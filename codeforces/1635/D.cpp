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
#define mod 1000000007

typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

const int N=1e6+10;
ll dp[N];
set<ll> se;
ll base(ll num){
    ll i,j;
    for(i=0,j=1;j<=num;i++){
        j*=2;
    }
    return i-1;
}
void solve(){
    int i,j;
    ll n,p;
    cin>>n>>p;
    ll a[n],temp,ans=0;
    se.clear();
    fo(i,n){
        cin>>a[i];
        se.insert(a[i]);
    }
    sort(a,a+n);
    for(i=n-1;i>=0;i--){
        temp = a[i];
        while(temp){
            // deb(temp);
            if(temp%2==1){
                temp/=2;
            }
            else if(temp%4==0){
                temp/=4;
            }
            else{
                break;
            }
            if(se.find(temp)!=se.end()){
                se.erase(a[i]);
                break;
            }
        }
    }
    memset(dp,0,sizeof dp);
    for(auto it : se){
        // deb2(it,base(it));
        dp[base(it)]++;
    }
    fo2(i,1,p-1){
        if(i>1){
            dp[i]=(dp[i] + dp[i-1] + dp[i-2])%mod;
        }
        else{
            dp[i]=(dp[i]+dp[i-1])%mod;
        }
    }
    fo2(i,0,p-1){
        ans=(ans+dp[i])%mod;
    }
    // fo2(i,0,p-1){
    //     cout<<dp[i]<<" ";
    // }cout<<nl;
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

