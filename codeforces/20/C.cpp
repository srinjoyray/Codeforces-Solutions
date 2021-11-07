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
const ll INF = 1e18;
vector<vector<pair<int, long long>>> adj(N); //{v,wt}
vector<long long> dist(N),path(N);
void dijkstra(int source) {
    
    dist.assign(N, INF);
    path.assign(N, -1);

    dist[source] = 0;
    set<pair<long long, long long>> q;
    q.insert({0, source});
    while (!q.empty()) {
        int node = (*q.begin()).second;
        q.erase(q.begin());

        for (auto edge : adj[node]) {
            int to = edge.first;
            long long len = edge.second;

            if (dist[node] + len < dist[to]) {
                q.erase({dist[to], to});
                dist[to] = dist[node] + len;
                path[to] = node;
                q.insert({dist[to], to});
            }
        }
    }
}
void solve(){
    int i,j;
    int n,m;
    cin>>n>>m;
    fo(i,m){
        ll u,v,wt;
        cin>>u>>v>>wt;
        adj[u].pb({v,wt});
        adj[v].pb({u,wt});
    }

    dijkstra(1);
    vi v;
    int node=n;
    
    while(node>0){
        v.pb(node);
        node=path[node];
    }

    reverse(all(v));
    if(v[0]!=1){
        cout<<"-1\n";
    }else{
        fo(i,v.size()){
            cout<<v[i]<<" ";
        }cout<<nl;
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

