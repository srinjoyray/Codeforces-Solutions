#include<bits/stdc++.h>
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define fo2(i,start,end) for(i=start;i<=end;i++)
#define rfo(i,n) for(i=n-1;i>=0;i--)
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
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
const int N=1e6+10;

void solve(){
    int i,j;
    ll a[3],m,mn,sum=0;
    fo(i,3){
        cin>>a[i];
        sum+=a[i]-1;
    }
    cin>>m;
    sort(a,a+3);
    if(m>sum){
        cout<<"NO\n";
        return;
    }
    mn=min(a[2]-a[1],m);
    a[2]-=mn;
    m-=mn;

    mn=min(a[1]-a[0],m/2);
    m-=2*mn;
    a[1]-=mn;
    a[2]-=mn;

    sort(a,a+3);
    // fo(i,3){
    //     cout<<a[i]<<" ";
    // }cout<<nl;
    if(a[2]>a[0]+a[1]+1){
        cout<<"NO\n";
    }
    else{
        cout<<"YES\n";
    }

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

