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
    int n,m,k,total,ans;
    vi v;
    cin>>n>>m>>k;
    total=n+m;
    if(k==1){
        for(j=1;j<=total;j+=n-1){
            v.pb(j);
            // deb(j);
        }
        cout<<v.size()<<nl;
        fo(j,v.size()){
            cout<<v[j]<<" ";
        }cout<<nl;
        return;
    }
    fo(i,k){
        v.pb(1);
    }
    for(i=n;i<=total;i+=n-1){
        if(i==total){
            v.pb(i);
            break;
        }
        v.pb(i);
        i++;
        fo(j,k-1){
            v.pb(i);
        }

    }
    cout<<v.size()<<nl;
    fo(j,v.size()){
        cout<<v[j]<<" ";
    }
    cout<<nl;
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
    return 0;
}

