#include<bits/stdc++.h>
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define fo2(i,start,end) for(i=start;i<=end;i++)
#define rfo(i,n) for(i=n-1;i>=0;i--)
#define lli long long int
#define ll long long int
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
    ll n,k;
    cin>>n>>k;
    ll a[n],ans=1,temp;
    fo(i,n){
        a[i]=1;
        cin>>a[i];
    }
    fo(i,n){
        cin>>temp;
    }
    sort(a,a+n);
    ll left,right;
    vl l(n),r(n);
    left=0;
    l[0]=1;
    for(i=1;i<n;i++){
        while(a[i]-a[left]>k){
            left++;
        }
        l[i]=max(l[i-1],(i-left+1));
        // deb(l[i]);
    }    
    right=n-1;
    r[n-1]=1;
    for(i=n-2;i>=1;i--){
        while(a[right]-a[i]>k){
            right--;
        }
        r[i]=max(r[i+1],(right-i+1));
        // deb(r[i]);
    }
    ans=1;
    fo(i,n-1){
        temp=l[i]+r[i+1];
        ans=max(ans,temp);
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

