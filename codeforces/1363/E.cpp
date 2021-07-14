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

ll a[N],b[N],c[N];
vi adj[N];
vi vis(N);
ll ans=0;
pii dfs(int node,int parent,ll mn){
    pii curr={0,0};
    if(b[node]!=c[node]){
        if(b[node]==1){
            curr.F++;
        }
        else{
            curr.S++;
        }
    }

    for(auto child :adj[node]){
        if(child==parent){
            continue;
        }
        pii p=dfs(child,node,min(mn,a[node]));
        curr.F+=p.F;
        curr.S+=p.S;
    }

    if(a[node]<mn){
        int temp=min(curr.F,curr.S);
        ans+=2*temp*a[node];
        curr.F-=temp;
        curr.S-=temp;
    }
    return curr;
}
void solve(){
    int i,j;
    int n;
    cin>>n;
    fo2(i,1,n){
        cin>>a[i]>>b[i]>>c[i];
    }
    fo(i,n-1){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    ans=0;
    vis.resize(n,0);
    pii p=dfs(1,-1,1e9+10);
    if(p.F>0 || p.S>0){
        ans=-1;
    }
    
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

