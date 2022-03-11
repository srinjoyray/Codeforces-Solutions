#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fo(i,n) for(i=0;i<n;i++)
#define fo2(i,start,end) for(i=start;i<=end;i++)
#define rfo(i,n) for(i=n-1;i>=0;i--)
#define deb(x) cerr<<#x<<"="<<x<<endl
#define deb2(x,y) cerr<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
#define ll long long
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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

const int N=110;
int vis[N][N];
string s[N];
int n,m,a1,b1,a2,b2;

void dfs(int x,int y){
    vis[x][y]=1;
    a1=min(a1,x);
    a2=max(a2,x);

    b1=min(b1,y);
    b2=max(b2,y);

    if(x<n-1 && vis[x+1][y]==0 && s[x+1][y]=='1'){
        dfs(x+1,y);
    }
    if(y<m-1 && vis[x][y+1]==0 && s[x][y+1]=='1'){
        dfs(x,y+1);
    }
    if(x>0 && vis[x-1][y]==0 && s[x-1][y]=='1'){
        dfs(x-1,y);
    }
    if(y>0 && vis[x][y-1]==0 && s[x][y-1]=='1'){
        dfs(x,y-1);
    }

}
void solve(){
    int i,j,i1,j1;
    cin>>n>>m;
    fo(i,n){
        cin>>s[i];
    }
    memset(vis,0,sizeof vis);
    fo(i,n){
        fo(j,m){
            if(s[i][j]=='1' && vis[i][j]==0){
                a1=a2=i , b1=b2=j;
                dfs(i,j);
                // deb2(a1,b1);
                // deb2(a2,b2);
                fo2(i1,a1,a2){
                    fo2(j1,b1,b2){
                        if(s[i1][j1]=='0'){
                            cout<<"NO\n";
                            return;
                        }
                    }
                }
            }
        }
    }

    cout<<"YES\n";
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

