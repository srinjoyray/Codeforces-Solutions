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
#define PI 3.141592653589793238
#define mod 1e9+7
map<int,vector<int>>m;
int col[10001];
void dfs(int node, int req){
    col[node]=req;
    int i,child;
    fo(i,m[node].size()){
        child=m[node][i];
        col[child]=req;
        // dfs(child,req);
    }
}
void solve(){
    int i,j;
    int n;
    cin>>n;
    int temp,c[n],count=0;
    for(i=2;i<=n;i++){
        cin>>temp;
        m[temp].pb(i);
    }
    fo2(i,1,n){
        cin>>c[i];
        col[i]=0;
    }
    fo2(i,1,n){
        if(c[i]==col[i]){
            fo(j,m[i].size()){
                col[m[i][j]]=c[i];
            }
            continue;
        }
        count++;
        dfs(i,c[i]);
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

