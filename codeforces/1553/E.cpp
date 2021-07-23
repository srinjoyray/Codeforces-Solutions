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
vi adj[N],vis(N);
void dfs(int node){
    // deb2(node,adj[node].size());
    vis[node]=1;
    for(int child : adj[node]){
        
        if(vis[child]==0){
            dfs(child);
        }
    }
}
bool check(int a[],int n,int k,int m){
    int i,j,val,pos,count=0,total=0;
    set<int> se;
    // deb(k);
    fo2(i,1,n){
        vis[i]=0;
        adj[i].clear();
    }
    fo2(i,1,n){
        pos=a[i]+k;
        if(pos>n){
            pos%=n;
        }
        
        if(pos!=i){
            adj[i].pb(pos);
            adj[pos].pb(i);
            // deb2(i,pos);
        }
        else{
            se.insert(i);
        }
    }
    fo2(i,1,n){
        if(se.find(i)!=se.end()){
            continue;
        }
        total++;
        if(vis[i]==0){
            // deb(i);
            dfs(i);
            count++;
        }
    }
    // deb2(total,count);
    if(m>=total-count){
        return true;
    }
    return false;
}
void solve(){
    int i,j;
    int n,m;
    cin>>n>>m;
    int a[n+1],val,count=0,temp;
    vi v,ans;
    map<int,int> mapp;
    fo2(i,1,n){
        cin>>a[i];
    }
    fo2(i,1,n){
        if(a[i]<=i){
            val=i-a[i];
        }
        else{
            val=n-(a[i]-i);
        }
        
        mapp[val]++;
    }
    fo(i,n){
        if(mapp[i]>=n-2*m){
            v.pb(i);
        }
    }
    fo(i,v.size()){
        if(check(a,n,v[i],m)){
            ans.pb(v[i]);
        }
    }
    
    cout<<ans.size()<<" ";
    fo(i,ans.size()){
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

