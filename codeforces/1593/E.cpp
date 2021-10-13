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
vi adj[N],rem(N),val(N),degree(N);
void solve(){
    int i,j;
    int n,k,count,ans=0;
    cin>>n>>k;
    fo2(i,1,n){
        rem[i]=0;
        degree[i]=0;
        adj[i].clear();
    }
    fo(i,n-1){
        int u,v;
        cin>>u>>v;
        // deb2(u,v);
        adj[u].pb(v);
        adj[v].pb(u);
        degree[u]++;
        degree[v]++;
    }
    set<int> se,s1;
    fo2(i,1,n){
        if(degree[i]<=1){
            rem[i]=1;
            se.insert(i);
            val[i]=1;
        }
    }
    count=2;
    while(se.size()){
        for(auto it :  se){
            for(int child : adj[it]){
                degree[child]--;
                // deb2(it,child);
                if(degree[child]<=1 && rem[child]==0){
                    rem[child]=1;
                    val[child]=count;
                    s1.insert(child);
                }
            }
        }
        se=s1;
        s1.clear();
        count++;
    }

    // fo2(i,1,n){
    //     cout<<val[i]<<" ";
    // }cout<<nl;

    fo2(i,1,n){
        if(val[i]>k){
            ans++;
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

