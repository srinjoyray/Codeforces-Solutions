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
void solve(){
    ll i,j;
    int n,m;
    cin>>n>>m;
    vector<pair<pl,ll>> v;
    map<ll,vpl> mapp;
    fo(i,m){
        ll l,r,x;
        cin>>l>>r>>x;
        v.pb({{l,r},x});
        mapp[l].pb({r,x});
    }
    ll b[n+1]={0},count,ans=0,temp,left,right,rem;
    sort(all(v));
    set<pl> se;
    fo2(i,1,n){
        fo(j,mapp[i].size()){
            se.insert({mapp[i][j]});
        }
        if(se.size()>0){
            b[i]=(*se.begin()).S;
            se.erase(se.begin());
        }
        while(se.size()>0 && (*se.begin()).F<=i){
            se.erase(se.begin());
        }
    }
    // fo2(i,1,n){
    //     cout<<b[i]<<" ";
    // }cout<<nl;
    for(j=1;j<=1e9;j*=2){
        count=0;
        fo2(i,1,n){
            if((b[i]&j)==j){
                count++;
            }
        }
        // deb2(j,count);
        if(count>0){
            left=power(2,count-1);
            rem=n-count;
            right=power(2,rem);
            // deb2(left,right);
            temp=(left*right)%mod;
            temp=(temp*j)%mod;
            ans=(ans+temp)%mod;
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

