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
map<int,int> dist,vis;
void dfs(int node){
    vis[node]=1;
    queue<int> q;
    q.push(node);
    dist[node]=0;

    while(!q.empty()){
        node=q.front();
        q.pop();
        for(auto child : adj[node]){
            if(vis[child]==0){
                dist[child]=dist[node]+1;
                vis[child]=1;
                q.push(child);
            }
        }
    }
}
void solve(){
    int i,j;
    int n,m;
    cin>>n>>m;
    ll a[n+1],v[n+1],t[n+1],sum=0;
    fo2(i,1,n){
        cin>>v[i];
    }
    fo2(i,1,n){
        cin>>t[i];
    }
    fo2(i,1,n){
        a[i]=t[i]-v[i];
        sum+=a[i];
        adj[i].clear();
    }

    fo(i,m){
        int n1,n2;
        cin>>n1>>n2;
        adj[n1].pb(n2);
        adj[n2].pb(n1);
    }
    // deb(sum);
    // cout<<sum%2<<nl;
    if(sum%2!=0){
        cout<<"NO\n";
        return;
    }

    vis.clear();
    dist.clear();
    dfs(1);
    // fo2(i,1,n){
    //     cout<<dist[i]<<" ";
    // }cout<<nl;
    fo2(i,1,n){
        fo(j,adj[i].size()){
            // deb(i);
            if((dist[i]+dist[adj[i][j]])%2==0){
                cout<<"YES\n";
                // deb2(i,j);
                // deb(dist[i]);
                // deb2(adj[i][j],dist[adj[i][j]]);
                return;
            }
        }
    }
    ll odd=0,even=0;

    fo2(i,1,n){
        if(dist[i]%2==1){
            odd+=a[i];
        }
        else{
            // deb(i);
            even+=a[i];
        }
    }
    // deb2(odd,even);
    if(odd==even){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
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

