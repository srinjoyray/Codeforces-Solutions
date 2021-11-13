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
vl adj[N],group(N),ans(N);
void dfs(int node,int parent,int val){
    // deb2(node,parent);
    group[node]=val;
    for(int child : adj[node]){
        if(child!=parent){
            dfs(child,node,val^1);
        }
    }
}
void solve(){
    int i,j,k;
    int n;
    cin>>n;
    fo2(i,1,n){
        adj[i].clear();
    }
    fo(i,n-1){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
        // deb2(u,v);
    }
    dfs(1,-1,0);
    int zero=0,msb;
    fo2(i,1,n){
        if(group[i]==0){
            zero++;
        }
    }
    // deb(zero);
    if(2*zero>n){
        fo2(i,1,n){
            group[i]=1^group[i];
        }
        zero=n-zero;
    }
    // deb(zero);
    vi v1,v2;
    fo2(i,1,n){
        for(j=1;j<=i;j*=2){
            msb=j;
        }
        // deb2(i,msb);
        if((msb&zero)==msb){
            v1.pb(i);
        }
        else{
            v2.pb(i);
        }
    }
    // deb2(v1.size(),v2.size());
    j=0,k=0;
    fo2(i,1,n){
        if(group[i]==0){
            ans[i]=v1[j];
            j++;
        }
        else{
            ans[i]=v2[k];
            k++;
        }
        // deb2(i,ans[i]);
    }

    fo2(i,1,n){
        cout<<ans[i]<<" ";
    }cout<<nl;

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

