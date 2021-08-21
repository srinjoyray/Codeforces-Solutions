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
const int N=4010;
int dp[N][N];
bool check(vi v,int val){
    int i,j,n;
    n=v.size();
    fo(j,N){
        dp[0][j]=0;
    }
    fo(i,N){
        dp[i][0]=1;
    }
    // deb2(n,N);
    // deb(val);
    fo2(i,1,n){
        fo(j,N){
            if(v[i-1]>j){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=dp[i-1][j]|dp[i-1][j-v[i-1]];
            }
        }
    }
    // fo2(i,0,n){
    //     fo(j,val+1){
    //         cout<<dp[i][j]<<"   ";
    //     }cout<<nl;
    // }
    if(dp[n][val]>0){
        return true;
    }
    return false;
}
void solve(){
    int i,j;
    int n;
    cin>>n;
    int a[2*n];
    set<int> se;
    fo(i,2*n){
        a[i]=i+1;
        cin>>a[i];
        se.insert(a[i]);
    }
    vi v;
    int count=0;
    i=2*n-1;
    while(i>=0){
        count++;
        if(a[i]==*se.rbegin()){
            v.pb(count);
            count=0;
        }
        se.erase(a[i]);
        i--;    
    }

    // fo(i,v.size()){
    //     cout<<v[i]<<" ";
    // }cout<<nl;

    if(check(v,n)){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
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

