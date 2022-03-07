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

const int N=1e5+10;
ll pref[N],freq[N];
ll find(vector<vl> v){
    int i,j,n,m;
    n = v.size();
    m = v[0].size();

    // fo(i,n){
    //     fo(j,m){
    //         cout<<v[i][j]<<" ";
    //     }cout<<nl;
    // }
    memset(freq,0,sizeof freq);
    memset(pref,0,sizeof pref);

    ll val,temp,ans=0;

    fo(i,n){
        fo(j,m){
            // deb2(i,j);
            val = v[i][j];
            temp = i*freq[val] - pref[val];
            ans+=temp;
            // deb2(ans,temp);
        }
        fo(j,m){
            val = v[i][j];
            freq[val]++;
            pref[val]+=i;
        }
    }
    // deb(ans);
    return ans;
}
void solve(){
    int i,j;
    int n,m;
    cin>>n>>m;
    ll a[n][m],ans;
    
    fo(i,n){
        fo(j,m){
            cin>>a[i][j];
        }
    }
    vector<vl> v1(n),v2(m);
    fo(i,n){
        fo(j,m){
            v1[i].pb(a[i][j]);
            v2[j].pb(a[i][j]);
        }
    }

    ans = find(v1) + find(v2);

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

