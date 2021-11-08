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
int a[N];
bool check(int n,int m,int mid){
    int b[n],i,j;
    fo(i,n){
        if(a[i]>=mid){
            b[i]=1;
        }
        else{
            b[i]=-1;
        }
    }
    fo2(i,1,n-1){
        b[i]+=b[i-1];
    }
    set<int> se;
    se.insert(0);
    i=0;
    j=m-1;
    while(j<n){
        if(*se.begin()<b[j] ){
            return true;
        }
        se.insert(b[i]);
        i++,j++;
    }
    return false;
}
void solve(){
    int i,j;
    int n,m;
    cin>>n>>m;
    fo(i,n){
        // a[i]=1;
        cin>>a[i];
    }
    int low=0,high=n,ans=0,mid;
    while(low<=high){
        mid=(low+high)/2;
        if(check(n,m,mid)){
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
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

