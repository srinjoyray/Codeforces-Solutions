#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fo(i,n) for(i=0;i<n;i++)
#define fo2(i,start,end) for(i=start;i<=end;i++)
#define rfo(i,n) for(i=n-1;i>=0;i--)
#define deb(x) cerr<<#x<<"="<<x<<endl
#define deb2(x,y) cerr<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
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
const ll inf = 1e18;
ll fact[20];
map<ll,ll> mapp;
ll bitwise(ll n){
    ll i=1,ans=0;
    while(i<=n){
        if((n&i) > 0){
            ans++;
        }
        i*=2;
    }
    return ans;
}
void subsets(ll n,vl v){
    ll sum=0;
    if(n>15){
        for(auto num : v){
            sum+=fact[num];
        }
        mapp[sum] = v.size();
        return;
    }
    else{
        subsets(n+1,v);
        v.pb(n);
        subsets(n+1,v);
    }
}
void solve(){
    int i,j;
    ll n,ans=inf,temp;
    // n=1e12;
    cin>>n;
    
    // deb(mapp.size());
    for(auto it : mapp){
        // deb2(it.F,it.S);
        temp = n-it.F;
        if(temp<0)break;
        ans = min(ans,bitwise(temp)+it.S);
    }

    cout<<ans<<nl;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t=1;
    cin>>t;
    ll i=1;
    fact[0]=1;
    for(i=1;i<=15;i++){
        fact[i]=fact[i-1]*i;
    }
    vl v;
    subsets(1,v);
    while(t--){
        solve();
    }
}

