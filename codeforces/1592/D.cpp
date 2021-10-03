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
vl adj[N],vis(N);
vpl v,v1,v2;
void dfs(int node,int parent){
    vis[node]=1;
    // if(parent!=-1){
    //     v.pb({parent,node});
    // }
    for(int child : adj[node]){
        if(vis[child]==0){
            v.pb({node,child});
            dfs(child,node);
        }
    }
    
}
ll ask(vpl v){
    set<ll> s1;
    ll i,input;
    fo(i,v.size()){
        s1.insert(v[i].F);
        s1.insert(v[i].S);
    }
    if(s1.size()==0){
        return 0;
    }
    cout<<"? "<<s1.size()<<" ";
    for(auto it : s1){
        cout<<it<<" ";
    }cout<<endl;

    cin>>input;
    return input;
}
void solve(){
    int i,j;
    int n;
    ll mx,start;
    cin>>n;
    set<pii> se;
    fo(i,n-1){
        int u,v;
        // u=i+1,v=i+2;
        cin>>u>>v;
        se.insert({u,v});
        adj[u].pb(v);
        adj[v].pb(u);
    }
    
    fo2(i,1,n){
        if(adj[i].size()==1){
            start=i;
            break;
        }
    }
    // deb(start);
    vis.clear();
    dfs(start,-1);
    // deb(v.size());
    // fo(i,v.size()){
    //     cout<<v[i].F<<" "<<v[i].S<<endl;
    // }
    mx=ask(v);
    while(v.size()>1){
        
        v1.clear();
        v2.clear();
        
        fo(i,v.size()){
            if(i<v.size()/2){
                v1.pb(v[i]);
            }
            else{
                v2.pb(v[i]);
            }
        }
        v.clear();
        // deb2(v1.size(),v2.size());
        if(ask(v1)==mx){
            fo(i,v1.size()){
                v.pb(v1[i]);
            }
        }
        else{
            fo(i,v2.size()){
                v.pb(v2[i]);
            }
        }
    }
    
    cout<<"! "<<v[0].F<<" "<<v[0].S<<endl;
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

