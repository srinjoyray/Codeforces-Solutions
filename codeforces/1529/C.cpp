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
const int N=1000000;
map<lli,vl> adj;
map<lli,lli> vis;
lli l[N],r[N],dp[N][2];

void dfs(lli node,lli parent){
    
    for(auto child: adj[node]){
        if(child!=parent){
            dfs(child,node);
            dp[node][0]+=max((dp[child][0]+abs(l[node]-l[child])),(dp[child][1]+abs(l[node]-r[child])));
            dp[node][1]+=max((dp[child][0]+abs(r[node]-l[child])),(dp[child][1]+abs(r[child]-r[node])));
        }
    }
    
}

void solve(){
    int i,j;
    int n;
    cin>>n;
    lli u,v,ans;
    fo2(i,1,n){
        cin>>l[i]>>r[i];
        // deb2(l[i],r[i]);
    }
    adj.clear();
    fo(i,n-1){
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    memset(dp,0,sizeof(dp));
    vis.clear();
    dfs(1,-1);
    ans=max(dp[1][0],dp[1][1]);
    cout<<ans<<nl;
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

