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

void solve(){
    int i,j;
    int n,m;
    cin>>n;
    int a[n],next[n];
    fo(i,n){
        cin>>a[i];
    }
    map<int,set<int>> mapp;
    for(i=n-1;i>=0;i--){
        mapp[a[i]].insert(i);
    }

    int last1=-1,last2=-1;
    vi v1,v2;
    fo(i,n){
        if(a[i]==last1){
            v1.pb(a[i]);
            continue;
        }
        if(a[i]==last2){
            v2.pb(a[i]);
            continue;
        }
        if(last1==-1){
            v1.pb(a[i]);
            last1=a[i];
            continue;
        }
        if(last2==-1){
            v2.pb(a[i]);
            last2=a[i];
            continue;
        }
        if(mapp[last1].lower_bound(i)==mapp[last1].end()){
            v1.pb(a[i]);
            last1=a[i];
            continue;
        }
        if(mapp[last2].lower_bound(i)==mapp[last2].end()){
            v2.pb(a[i]);
            last2=a[i];
            continue;
        }

        if(*mapp[last1].lower_bound(i)>=*mapp[last2].lower_bound(i)){
            v1.pb(a[i]);
            last1=a[i];
        }
        else{
            v2.pb(a[i]);
            last2=a[i];
        }

    }
    ll ans=0;
    v1.pb(n+10),v2.pb(n+10);
    fo(i,v1.size()-1){
        if(v1[i]!=v1[i+1]){
            ans++;
        }
    }
    fo(i,v2.size()-1){
        if(v2[i]!=v2[i+1]){
            ans++;
        }
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

