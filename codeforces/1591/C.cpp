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
ll find(vl v,ll k){
    ll i,n,sum=0;
    n=v.size();
    for(i=0;i<n;i+=k){
        if(i==0){
            sum+=v[i];
        }
        else{
            sum+=2*v[i];
        }
    }
    // deb(sum);
    return sum;
}
void solve(){
    int i,j;
    int n,k;
    cin>>n>>k;
    ll x[n],ans=0;
    vl v1,v2;
    fo(i,n){
        cin>>x[i];
        if(x[i]<0){
            v1.pb(-x[i]);
        }
        else{
            v2.pb(x[i]);
        }
    }
    sort(all(v1),greater<ll>());
    sort(all(v2),greater<ll>());

    ans = find(v1,k) + find(v2,k);

    if(v1.size()>0 && v2.size()>0){
        ans+=min(v1[0],v2[0]);
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

