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
map<lli,vl> adj;
map<lli,lli> dist,vis;
void dfs(int node){ 
    vis[node]=1;
    dist[node]=0;
    queue<int> q;
    int curr;
    q.push(node);
    while(!q.empty()){
        curr=q.front();
        q.pop();
        for(auto child : adj[curr]){
            if(vis[child]==0){
                vis[child]=1;
                q.push(child);
                dist[child]=dist[curr]+1;
            }
        }
    }
}
void solve(){
    int i,j;
    int n,a,b,da,db;
    cin>>n>>a>>b>>da>>db;
    adj.clear();
    fo(i,n-1){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vis.clear();
    dist.clear();
    dfs(1);
    int temp,mx=0,node;
    fo2(i,1,n){
        temp=dist[i];
        if(temp>mx){
            mx=temp;
            node=i;
        }
    }
    // deb(mx);
    vis.clear();
    dist.clear();
    dfs(node);
    fo2(i,1,n){
        temp=dist[i];
        // deb2(i,dist[i]);
        mx=max(mx,temp);
    }

    // deb2(mx,da);
    vis.clear();
    dist.clear();
    dfs(a);
    temp=dist[b];
    if(temp<=da){
        cout<<"Alice\n";
        return ;
    }
    if(2*da>=mx){
        cout<<"Alice\n";
        return;
    }
    if(db>2*da){
        cout<<"Bob\n";
    }
    else{
        cout<<"Alice\n";
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

