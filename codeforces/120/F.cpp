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
#define mod 1000000007

int diameter(int node,int n){
    map<int,vector<int>> m;
    map<int,int> vis,dist;
    int i,j,a,b;
    fo(j,n-1){
        cin>>a>>b;
        m[a].pb(b);
        m[b].pb(a);
    }
    queue<int> q;
    q.push(node);
    dist[node]=0;
    vis[node]=1;
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(auto child:m[curr]){
            if(vis[child]==0){
                vis[child]=1;
                dist[child]=dist[curr]+1;
                q.push(child);
            }
        }
    }
    int mx=0,pos=1;

    fo2(i,1,n){
        if(dist[i]>mx){
            mx=dist[i];
            pos=i;
        }
        // deb2(i,dist[i]);
    }

    // deb2(pos,mx);
    
    vis.clear();
    dist.clear();
    q.push(pos);
    dist[pos]=0;
    vis[pos]=1;
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(auto child:m[curr]){
            if(vis[child]==0){
                vis[child]=1;
                dist[child]=dist[curr]+1;
                q.push(child);
            }
        }
    }
    mx=0;
    fo2(i,1,n){
        mx=max(mx,dist[i]);
    }
    return mx;
}
void solve(){
    int i,j;
    int n,nodes,a,b,ans=0,res;
    cin>>n;
    fo(i,n){
        cin>>nodes;
        res=diameter(1,nodes);
        ans+=res;
        // deb(res);
    }
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

