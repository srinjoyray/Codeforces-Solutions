#include<bits/stdc++.h>
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define fo2(i,start,end) for(i=start;i<=end;i++)
#define rfo(i,n) for(i=n-1;i>=0;i--)
#define ll long long int
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
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
map<int,vi> adj;
int N;
vector<int> Centroid() {
        int n = N;
        vector<int> centroid;
        vector<int> sz(n);
        function<void (int, int)> dfs = [&](int u, int prev) {
                sz[u] = 1;
                bool is_centroid = true;
                for (auto v : adj[u]) if (v != prev) {
                        dfs(v, u);
                        sz[u] += sz[v];
                        if (sz[v] > n / 2) is_centroid = false;
                }
                if (n - sz[u] > n / 2) is_centroid = false;
                if (is_centroid) centroid.push_back(u);
        };
        dfs(0, -1);
        // deb(centroid.size());
        return centroid;
}
void solve(){
    int i,j;
    int node,mx=0;
    cin>>N;
    fo2(i,0,N){
        adj[i].clear();
    }
    fo(i,N-1){
        int x,y;
        cin>>x>>y;
        x--;y--;
        // deb2(x,y);
        adj[x].pb(y);
        adj[y].pb(x);
    }
    vector <int> centroid = Centroid();
    // deb(centroid.size());
    if(centroid.size()==1){
        cout<<centroid[0]+1<<" "<<adj[centroid[0]][0]+1<<nl;
        cout<<centroid[0]+1<<" "<<adj[centroid[0]][0]+1<<nl;
        return;
    }
    bool flag=false;
    int first=centroid[0],second=centroid[1];
    // deb2(first,second);
    for(auto child : adj[first]){
        if(child!=second){
            adj[first].erase(find(all(adj[first]),child));
            adj[child].erase(find(all(adj[child]),first));
            if(Centroid().size()==1){
                cout<<first+1<<" "<<child+1<<nl;
                cout<<second+1<<" "<<child+1<<nl;
            }
            break;
        }
    }
    if(Centroid().size()==2){
        swap(first,second);
        for(auto child: adj[first]){
            if(child!=second){
                 cout<<first+1<<" "<<child+1<<nl;
                 cout<<second+1<<" "<<child+1<<nl;
                 break;
            }
        }
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

