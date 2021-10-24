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
    ll a[n],b[n],gcd;
    fo(i,n){
        // a[i]=10000-(i%2);
        cin>>a[i];
    }
   
    if(n%2==0){
        for(i=0;i<n;i+=2){
            gcd=__gcd(abs(a[i]),abs(a[i+1]));
            b[i]=a[i+1]/gcd;
            b[i+1]=-a[i]/gcd;
        }
    }
    if(n%2==1){
        gcd=__gcd(abs(a[0]),abs(a[1]));
        gcd=__gcd(abs(a[2]),gcd);
        if(a[1]+a[2]!=0){ 
            b[0]=-(a[1]+a[2])/gcd;
            b[1]=a[0]/gcd;
            b[2]=a[0]/gcd;
        }
        else if(a[0]+a[2]!=0){
            b[1]=-(a[0]+a[2])/gcd;
            b[0]=a[1]/gcd;
            b[2]=a[1]/gcd;
        }
        else if(a[0]+a[1]!=0){
            b[2]=-(a[0]+a[1])/gcd;
            b[0]=a[2]/gcd;
            b[1]=a[2]/gcd;
        }
        for(i=3;i<n;i+=2){
            gcd=__gcd(abs(a[i]),abs(a[i+1]));
            b[i]=a[i+1]/gcd;
            b[i+1]=-a[i]/gcd;
        }
    }

    fo(i,n){
        cout<<b[i]<<" ";
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

