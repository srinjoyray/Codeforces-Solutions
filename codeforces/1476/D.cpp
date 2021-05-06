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
    int n;
    cin>>n;
    string s;
    int left[n+1]={0},right[n+1]={0},ans[n+1];
    cin>>s;
    fo(i,n){
        if(s[i]=='L'){
            if(i>0 && s[i-1]=='R'){
                left[i+1]=2+left[i-1];
            }
            else{
                left[i+1]=1;
            }
        }
        else{
            left[i+1]=0;
        }
    }
    for(i=n-1;i>=0;i--){
        if(s[i]=='R'){
            if(i<n-1 && s[i+1]=='L'){
                right[i]=2+right[i+2];
            }
            else{
                right[i]=1;
            }
        }
        else{
            right[i]=0;
        }
    }
    fo(i,n+1){
        ans[i]=left[i]+right[i]+1;
    }
    fo(i,n+1){
        cout<<ans[i]<<" ";
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
    return 0;
}

