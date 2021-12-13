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
typedef tree<pl, null_type, less_equal<pl>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

const int N=1e6+10;
struct node{
    int idx,l,k;
};
vi adj[N],freq(N),a(N),ans(N);
vector<node> mapp[N];
pbds A;
void dfs(int node,int parent){
    // deb2(node,parent);
    int val = a[node];
    if(freq[val]!=0){
        A.erase(A.upper_bound({freq[val],val}));
    }
    freq[val]++;
    A.insert({freq[val],val});


    // deb(A.size());
    for(auto q : mapp[node]){
        // deb2(q.idx,q.l);
        auto start = *A.upper_bound({q.l-1,N});
        int pos = A.order_of_key(start) + q.k;
        // deb(pos);
        if(pos>A.size()){
            ans[q.idx]=-1;
        }
        else{
            ans[q.idx]=(*A.find_by_order(pos-1)).S;
        }
    }

    for(auto child : adj[node]){
        if(child != parent){
            dfs(child,node);
        }
    }

    A.erase(A.upper_bound({freq[val],val}));
    freq[val]--;
    if(freq[val]>0){
        A.insert({freq[val],val});
    }

}

void solve(){
    int i,j;
    int n,q;
    cin>>n>>q;

    fo2(i,1,n){
        cin>>a[i];
    }
    fo2(i,1,n){
        adj[i].clear();
        mapp[i].clear();
    }

    fo2(i,2,n){
        int par;
        cin>>par;
        adj[par].pb(i);
        adj[i].pb(par);
    }
    fo(i,q){
        int v,l,k;
        cin>>v>>l>>k;
        node temp;
        temp.idx=i;
        temp.l=l;
        temp.k=k;
        mapp[v].pb(temp);
    }

    dfs(1,-1);

    fo(i,q){
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

