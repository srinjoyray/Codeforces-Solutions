#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fo(i,n) for(i=0;i<n;i++)
#define fo2(i,start,end) for(i=start;i<=end;i++)
#define rfo(i,n) for(i=n-1;i>=0;i--)
#define deb(x) cerr<<#x<<"="<<x<<endl
#define deb2(x,y) cerr<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
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
vl adj[N];
pl dp[N][2];
set<ll> sp;
pl add(pl a,pl b){
    return {a.F+b.F,a.S+b.S};
}
void dfs(int node,int parent){
    dp[node][0] = {0,0};
    dp[node][1] = {1,adj[node].size()};
    for(int child : adj[node]){
        if(child!=parent){
            dfs(child,node);
            if((dp[child][0].F>dp[child][1].F ) || (dp[child][0].F == dp[child][1].F && dp[child][0].S<dp[child][1].S)){
                dp[node][0] = add(dp[node][0] , dp[child][0]);
            }
            else{
                dp[node][0] = add(dp[node][0] , dp[child][1]);
            }
            dp[node][1] = add(dp[node][1] , dp[child][0]);
        }
    }
    // deb(node);
    // deb2(dp[node][0],dp[node][1]);
}

void find(int node,int parent,int pick){
    // deb2(node,pick);
    if(pick==1){
        sp.insert(node);
        for(int child : adj[node]){
            if(child != parent){
                find(child,node,0);
            }
        }
    }
    else{
        for(int child : adj[node]){
            if(child!=parent){
                if((dp[child][1].F > dp[child][0].F) || (dp[child][1].F==dp[child][0].F && dp[child][1].S<dp[child][0].S)){
                    find(child,node,1);
                }
                else{
                    find(child,node,0);
                }
            }
        }
    } 
}
void solve(){
    int i,j;
    int n;
    cin>>n;
    fo(i,n-1){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    if(n==2){
        cout<<"2 2\n1 1\n";
        return;
    }
    memset(dp,0,sizeof dp);

    dfs(1,-1);

    ll ans,sum=0,a[n+1];
    
    ans=max(dp[1][0].F,dp[1][1].F);
    if((dp[1][1].F > dp[1][0].F) || (dp[1][1].F==dp[1][0].F && dp[1][1].S<dp[1][0].S)){
        ans = dp[1][1].F;
        sum = dp[1][1].S + (n-ans);
        find(1,-1,1);
    }
    else{
        ans = dp[1][0].F;
        sum = dp[1][0].S + (n-ans);
        find(1,-1,0);
    }

    // fo2(i,1,n){
    //     deb(i);
    //     cerr<<dp[i][1].F<<" "<<dp[i][1].S<<nl;
    //     cerr<<dp[i][0].F<<" "<<dp[i][0].S<<nl;
    // }
    

    fo2(i,1,n){
        if(sp.find(i)!=sp.end()){
            a[i] = adj[i].size();
        }
        else{
            a[i] = 1;
        }
    }

    cout<<ans<<" "<<sum<<nl;
    fo2(i,1,n){
        cout<<a[i]<<" ";
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

