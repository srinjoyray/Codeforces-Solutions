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
const int N=1e6+10;
vi adj[N],dist(N),vis(N),leaves,parent(N);
void bfs(int node){
    vis[node]=1;
    dist[node]=0;
    queue<int> q;
    q.push(node);

    if(adj[node].size()==1){
        parent[node]=adj[node][0];
    }
    else{
        parent[node]=-1;
    }
    while(!q.empty()){
        node=q.front();
        q.pop();
        if(adj[node].size()==1){
            leaves.pb(node);
        }
        for(int child : adj[node]){
            if(vis[child]==0){
                vis[child]=1;
                dist[child]=dist[node]+1;
                q.push(child);
                parent[child]=node;
            }
        }
    }

    
}
void solve(){
    int i,j;
    int n;
    cin>>n;
    fo(i,n-1){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vis.resize(N,0);
    bfs(1);
    int mn,mx,parity;
    map<int,int> mapp;
    mn=1;
    mx=n-1;
    parity=dist[leaves[0]]%2;
    fo(i,leaves.size()){
        if(dist[leaves[i]]%2!=parity){
            mn=3;
        }
        mapp[parent[leaves[i]]]++;
    }
    for(auto x: mapp){
        if(x.S>1){
            mx-=(x.S-1);
        }
    }
    cout<<mn<<" "<<mx<<nl;
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

