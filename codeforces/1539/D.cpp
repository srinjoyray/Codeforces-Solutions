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
void solve(){
    int i,j;
    int n;
    cin>>n;
    ll a[n],b[n],sum=0;
    vpl v;
    fo(i,n){
        cin>>a[i]>>b[i];
        sum+=a[i];
        v.pb({b[i],a[i]});
    }

    sort(all(v));

    ll ans,rem=0,disc=0,curr=0,temp;
    fo(i,v.size()){
        // deb2(v[i].F,curr);
        if(v[i].F>curr){
            rem+=v[i].F-curr;
            curr=v[i].F;
        }
        if(rem+disc>sum){
            break;
        }
        temp=min(v[i].S,sum-(rem+disc));
        disc+=temp;
        curr+=temp;
        // deb2(disc,rem);
    }

    ans=(2*sum)-disc;
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

