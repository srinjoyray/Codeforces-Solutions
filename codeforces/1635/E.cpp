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

const int N=2e5+10;
vl col(N),vis(N),adj[N];
vector<vector<int>> edges;

void dfs(int node,int curr){
    vis[node]=1;
    for(int child : adj[node]){
        if(vis[child]==0){
            col[child]=curr^1;
            dfs(child,curr^1);
        }
    }
    
}

void solve(){
    int i,j;
    int n,m;
    cin>>n>>m;
    fo2(i,1,n)adj[i].clear();
    fo(i,m){
        int type,u,v;
        type=1,u=i+1,v=i+2;
        cin>>type>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
        edges.pb({u,v,type});
    }

    vis.assign(n+1, 0);
    
    fo2(i,1,n){
        if(vis[i]==0){
            col[i] = 0;
            dfs(i,0);
        }
    }
    fo2(i,1,n){
        cerr<<col[i]<<" ";
    }cerr<<nl;

    for(auto e : edges){
        int u,v;
        u=e[0] , v=e[1];
        if(col[u] == col[v]){
            cout<<"NO\n";
            return;
        }
    }

    vector<vl>new_adj(n+1);
    vl topo;
    vl indegree(n+1,0);
    queue<ll> q;
    vpl ans(n+1);
    for(auto e : edges){
        int u,v,type;
        u=e[0] , v=e[1] , type= e[2] ;
        if(col[u]==1)swap(u,v);
        if(type==2){
            new_adj[v].pb(u);
            indegree[u]++;
        }
        else{
            new_adj[u].pb(v);
            indegree[v]++;
        }
    }
    fo2(i,1,n){
        if(indegree[i]==0)q.push(i);
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.pb(node);
        for(int child : adj[node]){
            indegree[child]--;
            if(indegree[child]==0)q.push(child);
        }
    }
    if(topo.size()!=n){
        cout<<"NO\n";
        return;
    }
    fo(i,topo.size()){
        ans[topo[i]] = {col[topo[i]],i};
    }
    
    cout<<"YES\n";
    fo2(i,1,n){
        if(ans[i].F==0){
            cout<<"L ";
        }
        else{
            cout<<"R ";
        }
        cout<<ans[i].S<<nl;
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

