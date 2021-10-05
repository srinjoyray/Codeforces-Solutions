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
    int n;
    cin>>n;
    int q[n],a[n];
    set<int>se;
    fo(i,n){
        cin>>q[i];
        se.insert(i+1);
    }   
    a[0]=q[0];
    se.erase(q[0]);
    fo2(i,1,n-1){
        if(q[i]!=q[i-1]){
            a[i]=q[i];
            se.erase(q[i]);
        }
        else{
            a[i]=0;
        }
    }

    fo(i,n){
        if(a[i]==0){
            a[i]=*se.begin();
            se.erase(se.begin());
        }
    }
    int mx=0;
    fo(i,n){
        mx=max(mx,a[i]);
        if(q[i]!=mx){
            cout<<"-1\n";
            return;
        }
    }
    fo(i,n){
        cout<<a[i]<<" ";
    }cout<<nl;
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

