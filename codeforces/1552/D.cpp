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
int dp[11][N];
// bool check(vi v,int val){
//     int n,i,j;
//     deb(val);
//     n=v.size();
//     for(j=0;j<N;j++){
//         dp[0][j]=0;
//     }
//     for(i=0;i<n;i++){
//         dp[i][0]=1;
//     }
//     fo(i,n){
//         cout<<v[i]<<" ";
//     }cout<<nl;
    
//     for(i=1;i<=n;i++){
//         fo(j,N){
//             if(v[i-1]<=j){
//                 dp[i][j]=max(dp[i-1][j-v[i-1]],dp[i-1][j]);
//             }
//             else{
//                 dp[i][j]=dp[i-1][j];
//             }
//         }
//     }
//     // deb(val);
//     if(dp[n][val]>0){
//         return true;
//     }
//     return false;
// }
map<int,int> mapp;
void help(int curr,int idx,int v[],int n){
   
    if(idx==n){
        mapp[curr]++;
        return;
    }
    help(curr,idx+1,v,n);
    help(curr+v[idx],idx+1,v,n);
   
}


void solve(){
    int i,j;
    int n;
    cin>>n;
    int a[n];
    fo(i,n){
        cin>>a[i];
    }
    fo(i,n){
        if(a[i]==0){
            cout<<"YES\n";
            return;
        }
    }
    mapp.clear();
    help(0,0,a,n);
    
    for(auto x : mapp){
        if(x.S>1){
            cout<<"YES\n";
            return;
        }
        // cout<<x.F<<" "<<x.S<<nl;
    }
    cout<<"NO\n";
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

