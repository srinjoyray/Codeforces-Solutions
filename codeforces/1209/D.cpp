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
ll ans=0;
vl adj[N],vis(N);
void dfs(int node,int parent){
    vis[node]=1;
    // deb2(node,parent);
    for(int child : adj[node]){
        if(vis[child]==0){
            dfs(child,node);
        }
        else if(child!=parent){
            ans++;
        }
    }
}
void solve(){
    int i,j;
    int n,k;
    cin>>n>>k;
    // deb2(n,k);
    int x[k],y[k];
    map<pii,int> mapp;
    ll count=0;
    fo(i,k){
        cin>>x[i]>>y[i];
        // deb2(x[i],y[i]);
        if(x[i]>y[i]){
            swap(x[i],y[i]);
        }
        if(mapp[{x[i],y[i]}]>0){
            count++;
        }
        else{
            adj[x[i]].pb(y[i]);
            adj[y[i]].pb(x[i]);
        }
        mapp[{x[i],y[i]}]++;
    }
    // deb(count);
    fo2(i,1,n){
        // deb2(i,vis[i]);
        if(vis[i]==0){
            dfs(i,-1);
            // deb2(i,ans);
        }
    }
    ans/=2;
    ans+=count;
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

