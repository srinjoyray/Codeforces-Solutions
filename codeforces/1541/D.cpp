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
ll power(ll a,ll n){
    ll res=1;
    while(n){
        if(n%2){
            res=(res*a)%mod;
        }
        a=(a*a)%mod;
        n/=2;
    }
    return res;
}
void dfs(ll dist[],int node){
    queue<int> q;
    q.push(node);
    vis.clear();
    vis[node]=1;
    dist[node]=0;
    while(!q.empty()){
        node=q.front();
        q.pop();
        for(auto child : adj[node]){
            if(vis[child]==0){
                dist[child]=dist[node]+1;
                q.push(child);
                vis[child]=1;
            }
        }
    }
}
void solve(){
    int i,j;
    int n;
    cin>>n;
    fo(i,n-1){
        int x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    ll P[n+10][n+10]={0};
    fo(i,n){
        P[0][i]=1;
        P[i][0]=0;
    }
    for(i=1;i<n;i++){
        fo(j,n){
            ll denom=power(2,mod-2);
            P[i][j]+=(P[i-1][j]*denom)%mod;
            P[i][j]%=mod;
            if(j>0){
                P[i][j]+=(P[i][j-1]*denom)%mod;
                P[i][j]%=mod;
            }
        }
    }

    ll exp=0,distA[n+1],distB[n+1],dist,temp,rem;
    fo2(i,1,n){
        fo2(j,1,i-1){
            dfs(distA,i);
            dfs(distB,j);
            dist=distA[j];
            for(int start=1;start<=n;start++){
                temp=distA[start]+distB[start];
                rem=(temp-dist)/2;
                
                exp+=P[distA[start]-rem][distB[start]-rem];
                exp%=mod;
            }
        }
    }
    ll denom=power(n,mod-2);
    exp=(exp*denom)%mod;
    cout<<exp<<nl;
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

