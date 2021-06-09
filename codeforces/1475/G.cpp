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
const int N=200005;

void solve(){
    int i,j;
    int n;
    cin>>n;
    vi freq(N,0),ans(N,0);
    vi a(n);
    fo(i,n){
        cin>>a[i];
        // deb(a[i]);
        freq[a[i]]++;
    }

    for(i=N-1;i>=1;i--){
        ans[i]=freq[i];
        for(j=2*i;j<N;j+=i){
            ans[i]=max(ans[i],ans[j]+freq[i]);
        }
    }
    int mx;
    mx=*max_element(all(ans));
    cout<<(n-mx)<<nl;

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

