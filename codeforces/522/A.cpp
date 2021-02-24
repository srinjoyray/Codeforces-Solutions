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
map<string,vector<string>>m;
map<string,int> vis;
int dfs(string node,int val){
    vis[node]=1;
    int i,temp=0,mx;
    mx=val;
    string child;
    // deb2(node,val);
    fo(i,m[node].size()){
        child=m[node][i];
        if(vis[child]==0){
            temp=dfs(child,val+1);
        }
        mx=max(mx,temp);
    }
    // deb2(node,val);
    return mx;
}
void solve(){
    int i,j;
    int n,ans;
    cin>>n;
    string a,b,c;
    while(n--){
        cin>>a>>b>>c;
        transform(a.begin(), a.end(), a.begin(), ::tolower);
        transform(c.begin(), c.end(), c.begin(), ::tolower);
        m[a].pb(c);
        m[c].pb(a);
    }
    ans=dfs("polycarp",1);
    cout<<ans<<endl;
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

