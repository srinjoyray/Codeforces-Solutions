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
set<int> se;
void factors(ll n){
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            se.insert(i);
            se.insert(n/i);
        }
    }
}
void solve(){
    int i,j;
    int n;
    cin>>n;
    ll a[n],count=0,ans=1,temp,diff;
    fo(i,n){
        cin>>a[i];
    }
    se.clear();
    map<ll,ll> mapp;
    fo(i,n){
        fo2(j,i+1,n-1){
            diff=abs(a[i]-a[j]);
            // deb(diff);
            if(diff>0){
                factors(diff);
            }
            
        }
        mapp[a[i]]++;
        count=max(count,mapp[a[i]]);
    }
    if(count>=n/2){
        cout<<"-1\n";
        return;
    }
    
    for(auto it : se){
        count=0;
        mapp.clear();
        fo(j,n){
            if(a[j]>=0){
                temp=a[j]%it;
            }
            else{
                temp=(it-(abs(a[j])%it))%it;
            }
            mapp[temp]++;
            count=max(count,mapp[temp]);
        }
        if(count>=n/2){
            ans=it;
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

