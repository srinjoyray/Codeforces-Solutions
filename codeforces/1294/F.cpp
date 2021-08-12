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
vi adj[N],dist(N,0),vis(N,0);
set<int> path;
int a,b,c;
void bfs(int node){
    vis[node]=1;
    dist[node]=0;
    queue<int> q;
    q.push(node);
    while(!q.empty()){
        node=q.front();
        q.pop();
        for(int child : adj[node]){
            if(vis[child]==0){
                vis[child]=1;
                dist[child]=dist[node]+1;
                q.push(child);
            }
        }
    }

}
bool pathDfs(int node){
    vis[node]=1;
    if(node==b){
        path.insert(node);
        return true;
    }
    for(int child : adj[node]){
        if(vis[child]==0){
            if(pathDfs(child)){
                path.insert(node);
                return true;
            }
        }
    }
    return false;
}
pii bfs_node(int node){
    vis[node]=1;
    int mx=1,curr=node;
    dist[node]=1;
    queue<int> q;
    q.push(node);
    while(!q.empty()){
        node=q.front();
        q.pop();
        for(int child : adj[node]){
            if(vis[child]==0 && path.find(child)==path.end()){
                dist[child]=dist[node]+1;
                vis[child]=1;
                q.push(child);
                if(dist[child]>mx){
                    mx=dist[child];
                    curr=child;
                }
            }
        }
    }
    return {mx,curr};
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
    int mx=0,ans;

    bfs(1);
    fo2(i,1,n){
        if(dist[i]>mx){
            mx=dist[i];
            a=i;
        }
    }
    // deb2(mx,a);

    
    fill(vis.begin(), vis.end(), 0);
    fill(dist.begin(), dist.end(), 0);
    bfs(a);
    mx=0;
    fo2(i,1,n){
        if(dist[i]>mx){
            mx=dist[i];
            b=i;
        }
    }
    // deb2(mx,b);
    ans=mx;

    fill(vis.begin(), vis.end(), 0);
    pathDfs(a);

    if(a!=1 && b!=1){
        c=1;
    }
    else if(a!=2 && b!=2){
        c=2;
    }
    else{
        c=3;
    }

    fill(vis.begin(), vis.end(), 0);
    fill(dist.begin(), dist.end(), 0);
    mx=0;
    for(auto p : path){
        for(int child : adj[p]){
            if(path.find(child)==path.end()){
                pii temp;
                temp=bfs_node(child);
                if(temp.F>mx){
                    mx=temp.F;
                    c=temp.S;
                }
            }
        }
    }
    ans+=mx;
    cout<<ans<<nl;
    cout<<a<<" "<<b<<" "<<c<<nl;
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

