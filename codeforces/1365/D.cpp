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
string s[100];
int dp[100][100];
map<pii,int> vis;
void check(int i,int j,int n,int m){
    // deb2(i,j);
    vis[{i,j}]=1;
    
    if(s[i][j]=='#'){
        dp[i][j]=0;
        return;
    }
    
    dp[i][j]=1;
    
    
    if(i<n-1 && vis[{i+1,j}]==0){
        check(i+1,j,n,m);
    }
    if(j<m-1 && vis[{i,j+1}]==0){
        check(i,j+1,n,m);
    }
    if(i>0 && vis[{i-1,j}]==0){
        check(i-1,j,n,m);
    }
    if(j>0 && vis[{i,j-1}]==0){
        check(i,j-1,n,m);
    }
    
}
void solve(){
    int i,j;
    int n,m;
    cin>>n>>m;
    // deb2(n,m);
    int count=0;
    fo(i,n){
        cin>>s[i];
        // deb(s[i]);
        fo(j,m){
            if(s[i][j]=='G'){
                count++;
            }
        }
    }
    // deb(count);
    if(s[n-1][m-1]=='B'){
        cout<<"No\n";
        return;
    }
    if(n>1 && s[n-2][m-1]=='B' && count>0){
        cout<<"No\n";
        return;
    }
    if(m>1 && s[n-1][m-2]=='B' && count>0){
        cout<<"No\n";
        return;
    }
    fo(i,n){
        fo(j,m){
            if(s[i][j]=='B'){
                // deb2(i,j);
                if(i>0){
                    if(s[i-1][j]=='G'){
                        cout<<"No\n";
                        return;
                    }
                    else if(s[i-1][j]!='B'){
                        s[i-1][j]='#';
                    }
                }
                if(i<n-1){
                    if(s[i+1][j]=='G'){
                        cout<<"No\n";
                        return;
                    }
                    else if(s[i+1][j]!='B'){
                        s[i+1][j]='#';
                    }
                }
                if(j>0){
                    if(s[i][j-1]=='G'){
                        cout<<"No\n";
                        return;
                    }
                    else if(s[i][j-1]!='B'){
                        s[i][j-1]='#';
                    }
                }
                if(j<m-1){
                    if(s[i][j+1]=='G'){
                        cout<<"No\n";
                        return;
                    }
                    else if(s[i][j+1]!='B'){
                        s[i][j+1]='#';
                    }
                }
            }
        }
    }
    fo(i,n){
        fo(j,m){
            if(s[i][j]=='B'){
                s[i][j]='#';
            }
        }
    }
    memset(dp,0,sizeof(dp));
    int temp;
    vis.clear();
    check(n-1,m-1,n,m);
    
    // fo(i,n){
    //     fo(j,m){
    //         cout<<dp[i][j]<<" ";
    //     }cout<<nl;
    // }
    fo(i,n){
        fo(j,m){
            if(s[i][j]=='G' && dp[i][j]==0){
                cout<<"No\n";
                return;
            }
    
        }
    }
    cout<<"Yes\n";
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

