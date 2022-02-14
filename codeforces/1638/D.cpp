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

const int N=1e3+10;
ll vis[N][N],a[N][N],done[N][N];
set<pii> se;

bool check(int i,int j){
    set<int>s1;
    if(vis[i][j]==0)s1.insert(a[i][j]);
    if(vis[i+1][j]==0)s1.insert(a[i+1][j]);
    if(vis[i][j+1]==0)s1.insert(a[i][j+1]);
    if(vis[i+1][j+1]==0)s1.insert(a[i+1][j+1]);
    
    return s1.size()==1;
}
int find(int i , int j){
    if(vis[i][j]==0)return a[i][j];
    if(vis[i][j+1]==0)return a[i][j+1];
    if(vis[i+1][j]==0)return a[i+1][j];
    if(vis[i+1][j+1]==0)return a[i+1][j+1];
    return 1;
}
void solve(){
    int i,j;
    int n,m;
    cin>>n>>m;
    fo(i,n){
        fo(j,m){
            // a[i][j]=1;
            cin>>a[i][j];
            vis[i][j]=0;
            done[i][j]=0;
        }
    }
    
    fo(i,n-1){
        fo(j,m-1){
            if(check(i,j)){
                se.insert({i,j});
            }
        }
    }
    
    vector<vector<int>> ans;
    
    
    while(se.size()){
        // deb(se.size());
        auto p = *se.begin();
        se.erase(se.begin());
        
        i = p.F , j = p.S;
        // deb2(i,j);
        done[i][j]=1;
       
       
        vi temp = { i+1 , j+1, find(i,j) };
        ans.pb(temp);
        
        vis[i][j] = 1; vis[i+1][j] = 1 ,vis[i][j+1] = 1 , vis[i+1][j+1] = 1;
        
        int l,r;
        for(l=i-1;l<=i+1;l++){
            for(r=j-1;r<=j+1;r++){
                if(l<0 || l>=n-1 || r<0 || r>=m-1){
                    continue;
                }
                if(check(l,r) && done[l][r]==0){
                    se.insert({l,r});
                }
            }
        }
        
    }

    fo(i,n){
        fo(j,m){
            if(vis[i][j]==0){
                cout<<"-1\n";
                return;
            }
        }
    }
    cout<<ans.size()<<nl;
    for(i=ans.size()-1;i>=0;i--){
        fo(j,ans[i].size()){
            cout<<ans[i][j]<<" ";
        }
        cout<<nl;
    }

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

