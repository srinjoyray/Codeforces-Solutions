#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fo(i,n) for(i=0;i<n;i++)
#define fo2(i,start,end) for(i=start;i<=end;i++)
#define rfo(i,n) for(i=n-1;i>=0;i--)
#define deb(x) cout<<#x<<"="<<x<<endl
#define deb2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
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

const int N=1e6+10;
int n,m;
string s[N];
map<pii,int> vis;
void helper(int i,int j){
    // deb2(i,j);
    if(vis[{i,j}]>0 || s[i][j]=='#' || s[i][j]=='L'){
        return;
    }
    
    
    int count=0;
    if(i>0 && s[i-1][j]!='#' && vis[{i-1,j}]==0 ){
        count++;
    }
    if(j>0 && s[i][j-1]!='#'  && vis[{i,j-1}]==0){
        count++;
    }
    if(i<n-1 && s[i+1][j]!='#'  && vis[{i+1,j}]==0){
        count++;
    }
    if(j<m-1 && s[i][j+1]!='#'  && vis[{i,j+1}]==0){
        count++;
    }
    // deb(count);
    if(count<=1){
        s[i][j]='+';
        vis[{i,j}]=1;
        if(i>0 && s[i-1][j]=='.' && vis[{i-1,j}]==0){
            helper(i-1,j);
        }
        if(j>0 && s[i][j-1]=='.' && vis[{i,j-1}]==0){
            helper(i,j-1);
        }
        if(i<n-1 && s[i+1][j]=='.' && vis[{i+1,j}]==0){
            helper(i+1,j);
        }
        if(j<m-1 && s[i][j+1]=='.' && vis[{i,j+1}]==0){
            helper(i,j+1);
        }
    }
}
void solve(){
    int i,j;
    cin>>n>>m;
    
    fo(i,n){
        cin>>s[i];
    }
    vis.clear();
    fo(i,n){
        fo(j,m){
            if(s[i][j]=='L'){
                vis[{i,j}]=1;
                if(i<n-1){
                    helper(i+1,j);
                }
                if(j<m-1){
                    helper(i,j+1);
                }
                if(i>0){
                    helper(i-1,j);
                }
                if(j>0){
                    helper(i,j-1);
                }
                break;
            }
        }
    }

    fo(i,n){
        cout<<s[i]<<nl;
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

