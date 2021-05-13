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
    int n,k,ans=0,mn,mx,count,idx;
    cin>>n>>k;
    int a[n][n]={0};
    memset(a,0,sizeof(a));
    if(k%n==0){
        ans=0;
    }
    else{
        ans=2;
    }
    mn=k/n;
    mx=(k+n-1)/n;
    count=k%n;
    idx=0;
    fo(i,n){
        if(i<count){
            fo(j,mx){
                a[i][idx]=1;
                idx++;
                if(idx==n){
                    idx=0;
                }
            }
        }
        else{
            fo(j,mn){
                a[i][idx]=1;
                idx++;
                if(idx==n){
                    idx=0;
                }
            }
        }
    }
    cout<<ans<<nl;
    fo(i,n){
        fo(j,n){
            cout<<a[i][j];
        }cout<<nl;
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
    return 0;
}

