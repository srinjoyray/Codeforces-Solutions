#include<bits/stdc++.h>
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define fo2(i,start,end) for(i=start;i<=end;i++)
#define rfo(i,n) for(i=n-1;i>=0;i--)
#define lli long long int
#define deb(x) cout<<#x<<"="<<x<<endl
#define deb2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
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
typedef pair<lli, lli>	pl;
typedef vector<int>		vi;
typedef vector<lli>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
void solve(){
    int i,j;
    int n,k,z;
    cin>>n>>k>>z;
    lli a[n],sum=0,temp,mx=0,left,right,total,mx_sum=0;
    fo(i,n){
        cin>>a[i];
    }
    
    for(j=0;j<=min(z,k/2);j++){
        right=k-2*j;
        // deb(right);
        sum=0;
        mx=0;
        for(i=0;i<=right;i++){
            if(i<=n-2){
                temp=a[i]+a[i+1];
                mx=max(mx,temp);
            }   
            sum+=a[i];
        }
        // deb(sum);
        // deb2(mx,j);
        sum+=mx*j;
        // deb2(sum,temp);
        mx_sum=max(mx_sum,sum);
    }
    
    cout<<mx_sum<<nl;
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
    return 0;
}

