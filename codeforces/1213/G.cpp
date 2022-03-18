#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fo(i,n) for(i=0;i<n;i++)
#define fo2(i,start,end) for(i=start;i<=end;i++)
#define rfo(i,n) for(i=n-1;i>=0;i--)
#define deb(x) cerr<<#x<<"="<<x<<endl
#define deb2(x,y) cerr<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
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

const int N=2e5+10;
struct UnionFind {
	int n;
	vector<int> rank;
	vector<int> parent;
	// store other info as required
	UnionFind(int n) {
		rank.resize(n);
		fill(rank.begin(), rank.end(), 0);
		parent.resize(n);
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
	}
	int get(int a) {
		return parent[a] = (parent[a] == a ? a : get(parent[a]));
	}
	void merge(int a, int b) {
		a = get(a);
		b = get(b);
		if (a == b) {
			return;
		}
		if (rank[a] == rank[b]) {
			rank[a]++;
		}
		if (rank[a] > rank[b]) {
			parent[b] = a;
		} else {
			parent[a] = b;
		}
	}
};
vpl adj[N];

void solve(){
    int i,j;
    int n,m;
    cin>>n>>m;
    ll q[m],ans[m],curr=0,size[n],curr_ans=0,l,r,sz;
    vpl vq;
    fo(i,n-1){
        int u,v,w;
        cin>>u>>v>>w;
        u--,v--;
        adj[w].pb({u,v});
    }
    fo(i,m){
        cin>>q[i];
        vq.pb({q[i],i});
    }

    curr=0;
    UnionFind u1(n);
    fo(i,n)size[i]=1;
    sort(all(vq));
    fo(i,vq.size()){
        // deb2(vq[i].F,vq[i].S);
        while(curr<=vq[i].F){
            for(auto it : adj[curr]){
                l = size[u1.get(it.F)];
                r = size[u1.get(it.S)];
                sz = l + r ;
                u1.merge(it.F,it.S);
                size[u1.get(it.F)] = l+r;
                curr_ans += (sz*(sz-1)/2) - (l*(l-1)/2 + r*(r-1)/2);
            }
            curr++;
        }
        // deb(curr_ans);
        ans[vq[i].S] = curr_ans;
    }
    fo(i,m){
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

