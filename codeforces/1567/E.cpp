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
vl a;


struct node {
	ll tot;
	ll prefix;
	ll suffix;
};

struct SegTree {
	vector<node> tree;
	vector<ll> arr; // type may change
	int n;
	SegTree(int a_len) { // change if type updated
		arr = a;
		n = a_len;
		tree.resize(4 * n); 
        // fill(all(tree), 0);
		build(0, n - 1, 1);
	}
	void build(int start, int end, int index)  // Change according to operation
	{
		if (start == end)	{
			tree[index].tot = 1;
            tree[index].prefix = 1;
            tree[index].suffix = 1;
			return;
		}
		int mid = (start + end) / 2;
		build(start, mid, 2 * index);
		build(mid + 1, end, 2 * index + 1);

		tree[index].tot= tree[2 * index].tot + tree[2 * index + 1].tot;
        if(a[mid]<=a[mid+1]){
            tree[index].tot += tree[2*index].suffix*tree[2*index+1].prefix;
        }

        tree[index].prefix = tree[2*index].prefix;
        if(tree[2*index].prefix == mid-start+1 && a[mid]<=a[mid+1]){
            tree[index].prefix += tree[2*index+1].prefix;
        }

        tree[index].suffix = tree[2*index+1].suffix;
        if(tree[2*index+1].suffix == end-mid && a[mid]<=a[mid+1]){
            tree[index].suffix += tree[2*index].suffix;
        } 

        // deb2(index,tree[index].tot);
        // deb2(tree[index].prefix,tree[index].suffix);
        // deb2(start,end);
    }
	void update(int start, int end, int index, int query_index, ll val)  
	{
        if (start == end) {
            a[query_index] = val;
			return;
		}
		int mid = (start + end) / 2;
		if (mid >= query_index)
			update(start, mid, 2 * index, query_index, val);
		else
			update(mid + 1, end, 2 * index + 1, query_index, val);
		
        tree[index].tot= tree[2 * index].tot + tree[2 * index + 1].tot;
        if(a[mid]<=a[mid+1]){
            tree[index].tot += tree[2*index].suffix*tree[2*index+1].prefix;
        }

        tree[index].prefix = tree[2*index].prefix;
        if(tree[2*index].prefix == mid-start+1 && a[mid]<=a[mid+1]){
            tree[index].prefix += tree[2*index+1].prefix;
        }

        tree[index].suffix = tree[2*index+1].suffix;
        if(tree[2*index+1].suffix == end-mid && a[mid]<=a[mid+1]){
            tree[index].suffix += tree[2*index].suffix;
        } 

        // deb2(index,tree[index].tot);
        // deb2(tree[index].prefix,tree[index].suffix);
        // deb2(start,end);

	}
	node query(int start, int end, int index, int left, int right) { 
        node tmp;
        tmp.tot = 0;
        tmp.prefix = 0;
        tmp.suffix = 0;
		if (start > right || end < left)
			return tmp;
		if (start >= left && end <= right)
			return tree[index];
		int mid = (start + end) / 2;
		node l, r, ans;
		l = query(start, mid, 2 * index, left, right);
		r = query(mid + 1, end, 2 * index + 1, left, right);
		
        
        ans.tot = l.tot + r.tot;
		if(a[mid]<=a[mid+1]){
            ans.tot += l.suffix*r.prefix;
        }

        ans.prefix = l.prefix;
        if(l.prefix == mid-start+1 && a[mid]<=a[mid+1]){
            ans.prefix += r.prefix;
        }

        ans.suffix = r.suffix;
        if(r.suffix == end-mid && a[mid]<=a[mid+1]){
            ans.suffix += l.suffix;
        }

        return ans;
	}
};





void solve(){
    int i,j;
    int n,q;
    cin>>n>>q;
    
    fo(i,n){
        ll input;
        cin>>input;
        a.pb(input);
    }

    SegTree sgt(n);
    // fo2(i,1,n){
    //     cout<<i<<" "<<sgt.tree[i].tot<<" "<<sgt.tree[i].prefix<<" "<<sgt.tree[i].suffix<<nl;
    // }
    ll ans;
    while(q--){
        int type;
        cin>>type;
        // deb(type);
        if(type==1){
            int pos,val;
            cin>>pos>>val;
            pos--;
            // deb2(pos,val);
            sgt.update(0,n-1,1,pos,val);
            // fo(i,n){
            //     cout<<a[i]<<" ";
            // }cout<<nl;
        }
        else{
            int l,r;
            cin>>l>>r;
            l--,r--;
            ans=sgt.query(0,n-1,1,l,r).tot;
            cout<<ans<<nl;
        }
        // fo2(i,1,4){
        //     cout<<i<<" "<<sgt.tree[i].tot<<" "<<sgt.tree[i].prefix<<" "<<sgt.tree[i].suffix<<nl;
        // }
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

