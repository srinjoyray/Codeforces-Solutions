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
map<int,vi> adj;
map<int,int> vis;
map<int,pl> subtree;
ll a[1000000];
void dfs(int node){
    vis[node]=1;
    ll curr=a[node],count=0;
    // deb2(node,curr);
    for(auto child : adj[node]){
        if(vis[child]==0){
            // deb(child);
            dfs(child);
            curr+=subtree[child].F;
            count+=subtree[child].S;
        }
    }
    if(adj[node].size()==0){
        count=1;
    }
    subtree[node]={curr,count};

    // deb2(curr,node);
    // deb(count);
} 

void solve(){
    int i,j;
    int n;
    cin>>n;
    for(i=2;i<=n;i++){
        int p;
        cin>>p;
        adj[p].pb(i);
    }
   
    fo2(i,1,n){
        cin>>a[i];
    }
    
    dfs(1);

    ll temp,mx=0;
    fo2(i,1,n){
        // cout<<subtree[i].F<<" "<<subtree[i].S<<nl;
        ll ff,ss;
        ff=subtree[i].F;
        ss=subtree[i].S;
        temp=(ff+ss-1)/ss;
        mx=max(mx,temp);
    }
    cout<<mx<<nl;
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

