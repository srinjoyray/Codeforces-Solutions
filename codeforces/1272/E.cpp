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

void solve(){
    int i,j;
    int n;
    cin>>n;
    int a[n];
    vi ans(n+10,-1);
    map<int,vi> adj;
    queue<int> qq;
    fo(i,n){
        cin>>a[i];
    }
    fo(i,n){
        if(i+a[i]<n){
            adj[i+a[i]].pb(i);
            if((a[i]+a[i+a[i]])%2==1){
                ans[i]=1;
                qq.push(i);
            }
        }
        if(i-a[i]>=0){
            adj[i-a[i]].pb(i);
            if((a[i]+a[i-a[i]])%2==1){
                ans[i]=1;
                qq.push(i);
            }
        }
    }
    // fo(i,n){
    //     cout<<ans[i]<<" ";
    // }cout<<nl;
    while(!qq.empty()){
        int node=qq.front();
        // deb(node);
        qq.pop();
        for(auto child : adj[node]){
            // deb(child);
            if(ans[child]==-1 && (a[child]+a[node])%2==0){
                ans[child]=ans[node]+1;
                // deb(ans[child]);
                qq.push(child);
            }
        }
    }

    fo(i,n){
        cout<<ans[i]<<" ";
    }cout<<nl;
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

