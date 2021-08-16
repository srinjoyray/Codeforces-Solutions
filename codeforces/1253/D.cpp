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
vi adj[N],vis(N),val(N);
map<int,vi> mapp;
void dfs(int node,int curr){
    // deb2(node,curr);
    vis[node]=1;
    val[node]=curr;
    mapp[curr].pb(node);
    for(int child : adj[node]){
        if(vis[child]==0){
            dfs(child,curr);
        }
    }
}
void solve(){
    int i,j;
    int n,m;
    cin>>n>>m;
    fo(i,m){
        int u,v;
        cin>>u>>v;
        // deb2(u,v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    // deb(adj[2].size());
    int curr=1;
    fo2(i,1,n){
        if(vis[i]==0){
            // deb2(i,curr);
            dfs(i,curr);
            curr++;
        }
    }
    map<int,int> done;
    int mx=0,temp,ans=0;
    i=1;
    while(i<=n){
        temp=val[i];
        for(int p : mapp[temp]){
            mx=max(mx,p);
        }
        done[temp]++;
        // deb(mapp[temp].size());
        // deb2(i,mx);
        while(i<=mx){
            // deb2(i,val[i]);
            if(done[val[i]]==0){
                for(int p : mapp[val[i]]){
                    mx=max(mx,p);
                }
                done[val[i]]++;
                ans++;
            }
            // deb2335(mx,ans);
            i++;
        }
    }
    cout<<ans<<nl;
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

