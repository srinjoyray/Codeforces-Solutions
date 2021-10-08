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
set<int> adj[N],se;
map<pii,int> edge;
vl vis(N),colour(N);
bool flag;
void dfs(int node,int parent){
    // deb2(node,parent);
    vis[node]=1;
    se.insert(node);
    for(int child : adj[node]){
        // deb(child);
        if(vis[child]==0){
            if(edge[{node,child}]==0){
                colour[child]=colour[node];
            }
            else{
                colour[child]=colour[node]^1;
            }
            dfs(child,node);
        }
        else{
            if(edge[{node,child}]==0 && colour[node]!=colour[child]){
                flag=true;
            }
            if(edge[{node,child}]==1 && colour[node]==colour[child]){
                flag=true;
            }
        }
    }
}
void solve(){
    int i,j;
    int n,m;
    cin>>n>>m;
    fo2(i,1,n){
        adj[i].clear();
        vis[i]=0;
    }
    edge.clear();
    flag=false;
    fo(i,m){
        int u,v;
        string s;
        cin>>u>>v>>s;
        if(s[0]=='c'){
            if(edge[{u,v}]==1){
                flag=true;
            }
            edge[{u,v}]=0;
            edge[{v,u}]=0;
        }
        else{
            if(edge[{u,v}]==0 && adj[u].find(v)!=adj[u].end()){
                flag=true;
            }
            edge[{u,v}]=1;
            edge[{v,u}]=1;
        }
        // deb2(u,v);
        adj[u].insert(v);
        adj[v].insert(u);
    }   
    int ans=0,count,total;
    fo2(i,1,n){
        if(vis[i]==0){
            colour[i]=1;
            se.clear();
            dfs(i,-1);
            total=se.size();
            count=0;
            
            for(auto it : se){
                if(colour[it]==1){
                    count++;
                }
            }
            ans+=max(count,total-count);
        }
    }
    if(flag){
        cout<<"-1\n";
        return;
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

