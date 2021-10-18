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
vl adj1[N],adj[N],vis(N),v1;
set<pii> se;
void dfs(int node){
    // deb(node);
    vis[node]=1;
    for(int child : adj1[node]){
        if(vis[child]==0){
            // deb2(node,child);
            adj[node].pb(child);
            adj[child].pb(node);
            dfs(child);
        }
    }

}
bool path(int node,int end){
    vis[node]=1;
    v1.pb(node);
    if(node==end){
        return true;
    }
    for(int child : adj[node]){
        if(vis[child]==0){
            if(path(child,end)){
                int u,v;
                u=min(child,node);
                v=max(child,node);
                if(se.find({u,v})==se.end()){
                    se.insert({u,v});
                }
                else{
                    se.erase({se.find({u,v})});
                }
                return true;
            }
        }
    }

    v1.pop_back();
    return false;
}
void solve(){
    int i,j;
    int n,m;
    cin>>n>>m;
    fo2(i,1,n){
        adj1[i].clear();
        adj[i].clear();
        vis[i]=0;
    }
    fo(i,m){
        int u,v;
        cin>>u>>v;
        adj1[u].pb(v);
        adj1[v].pb(u);
    }
    dfs(1);
    int q;
    cin>>q;
    se.clear();
    
    vector<vl> ans;
    while(q--){
        int u,v;
        v1.clear();
        cin>>u>>v;
        fo2(i,1,n){
            vis[i]=0;
        }
        path(u,v);
        // deb2(u,v);
        ans.pb(v1);
        // fo(j,v1.size()){
        //     cout<<v1[j]<<" ";
        // }cout<<nl;
    }

    if(se.size()>0){
        cout<<"NO\n";
        int temp=0;
        // deb(se.size());
        fo2(i,1,n){
            vis[i]=0;  
        }
        for(auto it : se){
            vis[it.F]++;
            vis[it.S]++;
        }

        fo2(i,1,n){
            if(vis[i]%2==1){
                temp++;
            }
        }
        temp/=2;
        cout<<temp<<nl;
    }
    else{
        cout<<"YES\n";
        fo(i,ans.size()){
            cout<<ans[i].size()<<nl;
            fo(j,ans[i].size()){
                cout<<ans[i][j]<<" ";
            }cout<<nl;
        }
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

