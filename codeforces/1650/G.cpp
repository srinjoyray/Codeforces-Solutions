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

const int N=1e6+10;
vl adj[N],dist(N),vis(N);
ll dp[N][2],done[N][2];
void bfs(int node){
    vis[node]=1;
    dist[node]=0;
    queue<int> q;
    q.push(node);
    while(!q.empty()){
        node = q.front();
        q.pop();
        for(int child : adj[node]){
            if(vis[child] == 0){
                dist[child] = dist[node]+1;
                vis[child] = 1;
                q.push(child);
            }
        }
    }
}
int bfs2(int curr,int dest){
    queue<pl> q;
    q.push({curr,0LL});
    while(q.size()){
        pl p = q.front();
        q.pop();
        ll node = p.F , type = p.S;
        // deb2(p.F,p.S);
        if(done[node][type]==1)continue;
        done[node][type]=1;
        if(type==1){
            for(int child : adj[node]){
                if(dist[node]+1 == dist[child]){
                    dp[child][1] = (dp[child][1] + dp[node][1])%mod;
                    q.push({child,1});
                } 
            }
        }else{
            for(int child : adj[node]){
                if(dist[node]+1==dist[child]){
                    dp[child][0] = (dp[child][0] + dp[node][0])%mod;
                    q.push({child,0});
                }
                if(dist[node] == dist[child]){
                    dp[child][1] = (dp[child][1] + dp[node][0])%mod;
                    q.push({child,1});
                }
            }
        }

    }
    return (dp[dest][0] + dp[dest][1])%mod;
}
void solve(){
    int i,j;
    int n,m;
    cin>>n>>m;
    int s,t;
    cin>>s>>t;
    fo2(i,1,n){
        adj[i].clear();
        done[i][0] = done[i][1] = 0;
        dp[i][0] = dp[i][1] = 0;
    }
    fo(i,m){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    fo2(i,1,n)vis[i]=0;
    bfs(s);

    // fo2(i,1,n){
    //     cout<<dist[i]<<" ";
    // }cout<<nl;

    dp[s][0]=1; 
    ll ans = bfs2(s,t);

    fo2(i,1,n){
        // cout<<dp[i][0]<<" "<<dp[i][1]<<nl;
    }
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

