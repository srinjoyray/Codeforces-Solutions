#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fo(i,n) for(i=0;i<n;i++)
#define fo2(i,start,end) for(i=start;i<=end;i++)
#define rfo(i,n) for(i=n-1;i>=0;i--)
#define deb(x) cout<<#x<<"="<<x<<endl
#define deb2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
#define ll long long
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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

const int N=1e6+10;
const int inf=1e9;
vpii adj[N];
int vis[N][51];
vi dist(N);
struct comp
{
	bool operator() (pii a, pii b){
		return a.F > b.F;
	}
};
void solve(){
    int i,j;
    int n,m;
    cin>>n>>m;
    fo(i,m){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});

    }
    fo2(i,1,n){
        dist[i]=inf;
        fo(j,51){
            vis[i][j]=0;
        }
    }
    dist[1]=0;
    // set<pair<int,int>> se;
    priority_queue<pair<int,int>,vector<pii>, comp> se;
    int d,node,temp,rem;
    node=1,rem=0;
    se.push({dist[node],node*55+rem});

    while(se.size()){
        pair<int,int> p;
        p=se.top();
        se.pop();

        d=p.F;
        node=p.S/55;
        rem=p.S%55;

        // deb(node);
        // deb2(d,rem);
        if(vis[node][rem]==1){
            continue;
        }
        vis[node][rem]=1;

        for(auto it : adj[node]){
            int child,wt,new_d;
            child= it.F;
            wt=it.S;
            
            // deb2(child,wt);
            

            if(rem==0){
                // deb(vis[child][wt]);
                if(vis[child][wt]==0){
                    se.push({d,child*55+wt});
                }
            }
            else{
                new_d=d+(rem+wt)*(rem+wt);
                // deb2(new_d,child);
                dist[child]=min(dist[child],new_d);
                if(vis[child][0]==0){
                    se.push({new_d,child*55});
                }
            }
        }


    }


    fo2(i,1,n){
        if(dist[i]==inf){
            dist[i]=-1;
        }
        cout<<dist[i]<<" ";
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

