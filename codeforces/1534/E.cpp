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
int n,k;
vi v;
map<int,vi> adj;
map<int,int> vis,dist;
const int inf=INT_MAX;
void bfs(int node){
    queue<int> q;
    q.push(node);
    dist[node]=0;
    while(q.size()){
        node=q.front();
        q.pop();
        vis[node]=1;
        // deb(node);
        for(auto child : adj[node]){
            if(vis[child]==0){
                dist[child]=dist[node]+1;
                q.push(child);
                vis[child]=1;
            }
            if(child==n){
                return;
            }
        }
    }
}
void solve(){
    int i,j;
    int rem,val,node;
    cin>>n>>k;
    // memset(dp,true,sizeof dp);
    fo(i,n+1){
        for(j=0;j<=min(i,k);j++){
            rem=n-i;
            if(k-j>rem){
                continue;
            }
            val=i+k-2*j;
            adj[i].pb(val);
            // deb2(i,val);
        }
    }
    fo(i,n+1){
        dist[i]=inf;
        vis[i]=0;
    }
    bfs(0);
    /*fo(i,n+1){
        cout<<dist[i]<<" ";
    }cout<<nl;*/

    if(dist[n]==inf){
        cout<<"-1"<<endl;
        return;
    }

    node=n;
    val=dist[node];
    v.pb(node);
    while(val){
        // deb2(val,node);
        // deb(v.size());
        for(auto child : adj[node]){
            if(dist[child]==val-1){
                node=child;
                v.pb(child);
                val--;
                break;
            }
        }
    }
    reverse(all(v));
    // deb(v.size());
    /*fo(i,v.size()){
        cout<<v[i]<<" ";
    }cout<<nl;
    */
    set<int> sel,left;
    int change,ans=0,input;
    fo2(i,1,n){
        left.insert(i);
    }
    i=1;
    int p=2;
    while(i<v.size() ){
        vi curr,to_left,to_sel;
        change=v[i]-v[i-1];
        j=(k-change)/2;
        rem=k-j;
        // deb2(rem,j);
        while(j--){
            curr.pb(*sel.begin());
            to_left.pb(*sel.begin());
            sel.erase(sel.begin());
        }
        while(rem--){
            curr.pb(*left.begin());
            to_sel.pb(*left.begin());
            left.erase(left.begin());
        }

        fo(j,to_sel.size()){
            sel.insert(to_sel[j]);
        }
        fo(j,to_left.size()){
            left.insert(to_left[j]);
        }
        
        cout<<"? ";
        fo(j,curr.size()){
            cout<<curr[j]<<" ";
        }cout<<endl;
        cin>>input;
        // input=1;
        ans^=input;
        
        i++;
        // deb(i);
        // for(auto itr=sel.begin();itr!=sel.end();itr++){
        //     cout<<(*itr)<<" ";
        // }cout<<endl;
        // for(auto itr=left.begin();itr!=left.end();itr++){
        //     cout<<(*itr)<<" ";
        // }cout<<endl;
    }

    cout<<"! "<<ans<<endl;

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

