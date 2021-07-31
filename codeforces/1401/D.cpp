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
int n;
vl adj[N];
vl w;
ll dfs(int node,int parent){
    ll ans=1;
    // deb2(node,parent);
    for(auto child : adj[node]){
        if(child!=parent){
            ll temp=dfs(child,node);
            w.pb(temp*(n-temp));
            ans+=temp;
        }
    }
    // deb(ans);
    return ans;
}
void solve(){
    int i,j;
    
    cin>>n;
    fo2(i,1,n){
        adj[i].clear();
    }
    w.clear();
    fo(i,n-1){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,-1);
    sort(all(w));
    // fo(i,w.size()){
    //     cout<<w[i]<<" ";
    // }cout<<nl;
    int m;
    cin>>m;
    ll p[m];
    fo(i,m){
        cin>>p[i];
    }
    sort(p,p+m);
    // fo(i,m){
    //     cout<<p[i]<<" ";
    // }cout<<nl;
    vl v;
    ll temp,ans=0;
    if(m>=w.size()){
        fo(i,w.size()-1){
            temp=(p[i]*w[i])%mod;
            // deb2(p[i],w[i]);
            ans=(ans+temp)%mod;
        }
        temp=1;
        while(i<m){
            temp*=p[i];
            temp%=mod;
            i++;
        }
        temp=(temp*w[n-2])%mod;
        ans=(ans+temp)%mod;
    }
    else{
        sort(all(w),greater<ll>());
        sort(p,p+m,greater<ll>());
        fo(i,m){
            temp=(p[i]*w[i])%mod;
            ans=(ans+temp)%mod;
        }
        for(i=m;i<n-1;i++){
            ans=(ans+w[i])%mod;
        }
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

