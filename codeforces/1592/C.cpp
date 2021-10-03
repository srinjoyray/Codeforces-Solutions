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
ll a[N],k,all,start,pos;
vl adj[N],vis(N);
map<ll,ll> mapp;
bool flag;

ll dfs(int node){
    vis[node]=1;
    ll temp=a[node];
    for(int child : adj[node]){
        if(vis[child]==0){
            temp^=dfs(child);
        }
    }
    mapp[temp]++;
    // deb2(node,temp);

    if(temp==all && node!=start){
        if(pos==-1){
            pos=node;
        }
    }
    return temp;
}
ll dfs2(int node){
    vis[node]=1;
    ll temp=a[node];
    for(int child : adj[node]){
        if(vis[child]==0 && child !=pos){
            temp^=dfs2(child);
        }
    }
    
    // deb2(node,temp);

    if(temp==all && node!=start){
        flag=true;
    }
    return temp;
}
void solve(){
    int i,j;
    int n;
    cin>>n>>k;
    
    fo2(i,1,n){
        adj[i].clear();
        vis[i]=0;
    }
    all=0;
    fo2(i,1,n){
        cin>>a[i];
        // deb(a[i]);
        all^=a[i];
    }
    // deb(all);
    
    fo(i,n-1){
        int u,v;
        cin>>u>>v;
        // deb2(u,v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    fo2(i,1,n){
        if(adj[i].size()==1){
            start=i;
            break;
        }
    }
    if(all==0){
        cout<<"YES\n";
        return;
    }
    if(k==2){
        cout<<"NO\n";
        return;
    }
    
    flag=false;
    pos=-1;
    // deb(start);
    dfs(start);
    
    fo2(i,1,n){
        vis[i]=0;
    }
    // deb(pos);
    if(pos!=-1){
        dfs2(start);
    }
    if(flag){
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

