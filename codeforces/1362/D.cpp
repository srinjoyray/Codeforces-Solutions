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
vi adj[N];
void solve(){
    int i,j;
    int n,m;
    cin>>n>>m;
    set<pii>se;
    int a[n+1],vis[n+1]={0},node,mx;
    fo(i,m){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    fo2(i,1,n){
        cin>>a[i];
        se.insert({a[i],i});
    }
    vi ans;
    for(auto it : se){
        ans.pb(it.S);
    }
    set<int>s1;
    
    fo(i,ans.size()){
        node=ans[i];
        vis[node]=1;
        // deb(node);
        s1.clear();
        for(int child : adj[node]){
            if(vis[child]==1 && a[child]<=a[node]){
                // deb(a[child]);
                s1.insert(a[child]);
            }
        }
        // deb(s1.size());
        if(s1.size()==a[node]-1){
            if(s1.size()==0 || *s1.rbegin()==a[node]-1){
                continue;
            }
        }
        cout<<"-1\n";
        return;
        
    }

    fo(i,ans.size()){
        cout<<ans[i]<<" ";
    }
    cout<<nl;
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

