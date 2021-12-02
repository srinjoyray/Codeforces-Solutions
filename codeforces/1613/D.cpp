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

ll dp1[N],dp2[N];
void solve(){
    int i,j;
    int n;
    cin>>n;
    ll a[n],num,ans=0;
    fo(i,n){
        cin>>a[i];
    }
    fo2(i,0,n){
        dp1[i]=0;
        dp2[i]=0;
    }
    dp1[0]=1;
    fo(i,n){
        num=a[i];
        dp1[num+1] = (2*dp1[num+1] + dp1[num])%mod;

        if(num>0){
            dp2[num-1] = (2*dp2[num-1] + dp1[num-1])%mod;
        }

        dp2[num+1] = (2*dp2[num+1])%mod;
    }

    fo2(i,0,n){
        ans=(ans+dp1[i]+dp2[i])%mod;
    }
    ans=(ans+mod-1)%mod;
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

