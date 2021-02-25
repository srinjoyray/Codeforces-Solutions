#include<bits/stdc++.h>
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define fo2(i,start,end) for(i=start;i<=end;i++)
#define rfo(i,n) for(i=n-1;i>=0;i--)
#define lli long long int
#define deb(x) cout<<#x<<"="<<x<<endl
#define deb2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define tr(it,a) for(auto it=a.begin(); it!=a.end();it++)
#define nl '\n'
#define PI 3.141592653589793238
#define mod 1e9+7
vector<int> ar[100001];
int vis[100001],a[100001],ans[100001];
void dfs(int node,int val,int m){
    vis[node]=1;
    if(a[node]==1){
        val++;
    }
    else{
        val=0;
    }
    // deb2(node,val);
    if(val>m){
        return;
    }
    int flag=0;
    for(int child:ar[node]){
        // deb(val);
        if(vis[child]==0){
            dfs(child,val,m);
            flag=1;
        }
        
    }
    if(flag==0){
        ans[node]=1;
    }
}
void solve(){
    int i,j;
    int n,m,x,y,count=0;
    cin>>n>>m;
    fo2(i,1,n){
        cin>>a[i];
        vis[i]=0;
        ans[i]=0;
    } 
    fo(i,n-1){
        cin>>x>>y;
        ar[x].pb(y);
        ar[y].pb(x);
    }
    dfs(1,0,m);
    fo2(i,1,n){
        if(ans[i]==1){
            count++;
        }
        // deb2(i,ans[i]);
    }
    
    cout<<count<<endl;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

