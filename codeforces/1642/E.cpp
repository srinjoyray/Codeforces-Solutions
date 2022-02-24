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
const int inf = INT_MAX;
struct Segtree {
	vector<ll> tree;
	int n;
	Segtree(int a_len) { // change if type updated
		n = a_len;
		tree.resize(4 * n); fill(all(tree), inf);
		build(0, n - 1, 1);
	}
	void build(int start, int end, int index)  // Change according to operation
	{
		if (start == end)	{
			tree[index] = inf;
			return;
		}
		int mid = (start + end) / 2;
		build(start, mid, 2 * index);
		build(mid + 1, end, 2 * index + 1);
		tree[index]=min(tree[2 * index] , tree[2 * index + 1]);
	}
	void update(int start, int end, int index, int query_index, ll val)  
	{
		if (start == end) {
			tree[index] = min(tree[index],val);
			return;
		}
		int mid = (start + end) / 2;
		if (mid >= query_index)
			update(start, mid, 2 * index, query_index, val);
		else
			update(mid + 1, end, 2 * index + 1, query_index, val);
		tree[index]=min(tree[2 * index] , tree[2 * index + 1]);
	}
	ll query(int start, int end, int index, int left, int right) { 
		if (start > right || end < left)
			return inf;
		if (start >= left && end <= right)
			return tree[index];
		int mid = (start + end) / 2;
		ll l, r, ans;
		l = query(start, mid, 2 * index, left, right);
		r = query(mid + 1, end, 2 * index + 1, left, right);
		ans=min(l,r);
       
		return ans;
	}
};
void solve(){
    int i,j;
    int n,q;
    cin>>n>>q;
    Segtree sgt(n+2);
    set<int> se;
    fo2(i,0,n+1){
        se.insert(i);
    }
    while(q--){
        int type;
        cin>>type;
        if(type==0){
            int l,r,x;
            cin>>l>>r>>x;
            if(x==0){
                while(se.lower_bound(l)!=se.end() && *se.lower_bound(l)<=r){
                    se.erase(se.lower_bound(l));
                }
            }
            else{
                // deb2(l,r);
                sgt.update(0,n+1,1,l,r);
            }
        }
        else{
            int l,r,pos,temp;
            cin>>pos;
            if(se.find(pos)==se.end()){
                cout<<"NO\n";
                continue;
            }
            
            l=*(--se.lower_bound(pos));
            r = *(se.upper_bound(pos));
            
            
            // deb2(l,r);
            temp = sgt.query(0,n+1,1,l+1,r);
            // deb(temp);
            if(temp<r){
                cout<<"YES\n";
            }
            else{
                cout<<"N/A\n";
            }
        }
    }
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

