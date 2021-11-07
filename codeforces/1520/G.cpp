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

const int N=2e3+10;
const ll inf=1e18;
ll a[N][N],dp1[N][N],dp2[N][N],n,m,w,vis[N][N];

void solve(){
    int i,j;

    cin>>n>>m>>w;
    fo(i,n){
        fo(j,m){
            cin>>a[i][j];
        }
    }
    fo(i,n){
        fo(j,m){
            dp1[i][j]=inf;
            dp2[i][j]=inf;
            vis[i][j]=0;
        }
    }

    queue<pair<pl,ll>> q;
    q.push({{0,0},0});
    vis[0][0]=1;
    while(!q.empty()){
        pair<pl,ll> p;
        p=q.front();
        q.pop();
        i=p.F.F,j=p.F.S;
        dp1[i][j]=p.S;
        if(i>0 && a[i-1][j]!=-1 && vis[i-1][j]==0){
            vis[i-1][j]=1;
            q.push({{i-1,j},p.S+w});
        }
        if(i<n-1 && a[i+1][j]!=-1 && vis[i+1][j]==0){
            vis[i+1][j]=1;
            q.push({{i+1,j},p.S+w});
        }
        if(j>0 && a[i][j-1]!=-1 && vis[i][j-1]==0){
            vis[i][j-1]=1;
            q.push({{i,j-1},p.S+w});
        }
        if(j<m-1 && a[i][j+1]!=-1 && vis[i][j+1]==0){
            vis[i][j+1]=1;
            q.push({{i,j+1},p.S+w});
        }

    }

    fo(i,n){
        fo(j,m){
            vis[i][j]=0;
        }
    }

    q.push({{n-1,m-1},0});
    vis[n-1][m-1]=1;
    while(!q.empty()){
        pair<pl,ll> p;
        p=q.front();
        q.pop();
        i=p.F.F,j=p.F.S;
        dp2[i][j]=p.S;
        if(i>0 && a[i-1][j]!=-1 && vis[i-1][j]==0){
            vis[i-1][j]=1;
            q.push({{i-1,j},p.S+w});
        }
        if(i<n-1 && a[i+1][j]!=-1 && vis[i+1][j]==0){
            vis[i+1][j]=1;
            q.push({{i+1,j},p.S+w});
        }
        if(j>0 && a[i][j-1]!=-1 && vis[i][j-1]==0){
            vis[i][j-1]=1;
            q.push({{i,j-1},p.S+w});
        }
        if(j<m-1 && a[i][j+1]!=-1 && vis[i][j+1]==0){
            vis[i][j+1]=1;
            q.push({{i,j+1},p.S+w});
        }

    }

    // fo(i,n){
    //     fo(j,m){
    //         cout<<dp1[i][j]<<" ";
    //     }cout<<nl;
    // }cout<<nl;
    // fo(i,n){
    //     fo(j,m){
    //         cout<<dp2[i][j]<<" ";
    //     }cout<<nl;
    // }

    ll ans=inf,mn1=inf,mn2=inf;

    fo(i,n){
        fo(j,m){
            if(a[i][j]>0){
                mn1=min(mn1,dp1[i][j]+a[i][j]);
                mn2=min(mn2,dp2[i][j]+a[i][j]);
            }
        }
    }
    // deb2(mn1,mn2);
    ans=min(dp2[0][0],mn1+mn2);

    if(ans>=inf){
        cout<<"-1\n";
    }
    else{
        cout<<ans<<nl;
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

