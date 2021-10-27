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
set<int> adj[N],rev[N],adj2[N];
int dist[N],vis1[N];
void bfs(int node){
    vis1[node]=1;
    queue<int>q;
    q.push(node);
    dist[node]=0;
    while(!q.empty()){
        node=q.front();
        // deb(node);
        q.pop();
        for(int child : adj[node]){
            if(vis1[child]==0){
                vis1[child]=1;
                q.push(child);
                dist[child]=dist[node]+1;
            }
        }
    }
}
void solve(){
    int i,j;
    int n;
    cin>>n;
    int a[n+1],b[n+1],vis[n+1]={0},node,end,l,r;
    set<int> se;
    fo2(i,1,n){
        cin>>a[i];
    }
    fo2(i,1,n){
        cin>>b[i];
    }
    fo2(i,1,n-1){
        se.insert(i);
    }
    fo2(i,1,n){
        if(a[i]>=i){
            adj[i].insert(0);
            rev[0].insert(i);
        }
    }
    queue<int>q;
    q.push(n);
    vis[n]=1;
    while(q.size()){
        node=q.front();
        q.pop();
        // deb(node);
        l=node-a[node];

        auto it = se.lower_bound(l);
        vi del;
        // deb2(l,*it);
        while(it !=se.end() && *it<node){
            end =*it+b[*it];

            if(node!=end){
                adj[node].insert(end);
                rev[end].insert(node);
                adj2[end].insert(*it);
                // deb2(end,*it);
            }
            // deb2(*it,end);
            if(vis[end]==0){
                q.push(end);
                vis[end]=1;
            }
            del.pb(*it);
            it++;
        }
        // deb2(node,*it);
        fo(i,del.size()){
            se.erase(del[i]);
        }
        // deb(se.size());
    }

    fo2(i,1,n){
        // deb2(i,adj[i].size());
        for(int child : adj[i]){
            // cout<<i<<" "<<child<<nl;
        }
    }
    memset(dist,-1,sizeof dist);
    bfs(n);
    // fo2(i,0,n){
    //     cout<<dist[i]<<" ";
    // }cout<<nl;

    if(dist[0]==-1){
        cout<<"-1\n";
        return;
    }

    vi path;
    node=0;
    while(true){
        int after=node;
        path.pb(node);
        for(int parent : rev[node]){
            // deb2(node,parent);
            if(dist[parent]==dist[node]-1){
                after=parent;
                break;
            }
        }
        if(after!=node){
            node=after;
        }
        else{
            break;
        }
    }
    reverse(all(path));

    // fo(i,path.size()){
    //     cout<<path[i]<<" ";
    // }cout<<nl;

    vi ans;
    fo2(i,1,path.size()-2){
        node=path[i-1]-a[path[i-1]];
        // deb2(path[i],node);
        ans.pb(*adj2[path[i]].lower_bound(node));
    }
    ans.pb(0);
    cout<<dist[0]<<nl;
    fo(i,ans.size()){
        cout<<ans[i]<<" ";
    }cout<<nl;
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

