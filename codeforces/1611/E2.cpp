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
vl adj[N],multi_dist(N),vis(N),dist_root(N);

void bfs_root(int node){
    int i;
    queue<int> q;
    q.push(node);
    vis[node]=1;
    dist_root[node]=0;
    while(!q.empty()){
        node=q.front();
        q.pop();
        for(int child : adj[node]){
            if(vis[child]==0){
                vis[child]=1;
                q.push(child);
                dist_root[child]=dist_root[node]+1;
            }
        }
    }
}
void multi_source_bfs(vi v){
    int i,node;
    queue<int> q;
    fo(i,v.size()){
        multi_dist[v[i]]=0;
        vis[v[i]]=1;
        q.push(v[i]);
    }
    
    while(!q.empty()){
        node=q.front();
        q.pop();
        for(int child : adj[node]){
            if(vis[child]==0){
                vis[child]=1;
                q.push(child);
                multi_dist[child]=multi_dist[node]+1;
            }
        }
    }
    
}
void solve(){
    int i,j;
    int n,k;
    cin>>n>>k;
    fo2(i,1,n){
        adj[i].clear();
        vis[i]=0;
    }
    vi v;
    fo(i,k){
        int x;
        cin>>x;
        v.pb(x);
    }

    fo(i,n-1){
        int u,v;
        cin>>u>>v;
        // deb2(u,v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    multi_source_bfs(v);

    fo2(i,1,n){
        vis[i]=0;
    }
    
    bfs_root(1);
    bool flag=false;
    fo2(i,2,n){
        if(adj[i].size()==1 && dist_root[i]<multi_dist[i]){
            flag=true;
            break;
        }
    }

    if(flag){
        cout<<"-1\n";
        return;
    }
    int ans=0;
    fo2(i,1,n){
        vis[i]=0;
    }
    queue<int> q;
    vis[1]=0;
    q.push(1);
    while(!q.empty()){
        i=q.front();
        q.pop();
        // deb2(i,q.size());
        if(dist_root[i]>=multi_dist[i]){
            ans++;
            continue;
        }
        for(int child :  adj[i]){
            if(vis[child]==0){
                vis[child]=1;
                q.push(child);
            }
        }
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

