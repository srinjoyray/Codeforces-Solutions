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
vl adj[N],vis(N),type(N);
ll bud,leaves,flag;
void dfs(int node){
    vis[node]=1;
    int curr=0;
    for(int child : adj[node]){
        if(vis[child]==0){
            dfs(child);
            if(type[child]==1){
                curr++;
            }
        }
    }

    if(curr==0){
        type[node]=1;
    }
    else{
        bud++;
        type[node]=2;
    }
}
void solve(){
    int i,j;
    int n,ans;
    cin>>n;
    fo2(i,1,n){
        adj[i].clear();
        vis[i]=0;
    }
    fo(i,n-1){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }


    bud=0; 
    leaves=0;
    flag=0;
   
    dfs(1);
    leaves=n-bud;
    
    // deb2(leaves,bud);
    // deb(type[1]);
    ans=leaves-bud+1;
    if(type[1]==1){
        ans--;
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

