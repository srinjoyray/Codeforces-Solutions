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
const ll inf = 1e18;

struct Segtree {
	vector<ll> tree;
	vector<ll> arr; // type may change
	int n;
	Segtree(int a_len, vector<ll> &a) { // change if type updated
		arr = a;
		n = a_len;
		tree.resize(4 * n); fill(all(tree), 0);
		build(0, n - 1, 1);
	}
	void build(int start, int end, int index)  // Change according to operation
	{
		if (start == end)	{
			tree[index] = arr[start];
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
			tree[index] = val;
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
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    vl v;
    map<int,set<int>> mapp;
    fo(i,n){
        v.pb(s[i]-'a');
        mapp[s[i]-'a'].insert(i);
    }
    Segtree sgt(n,v);
    ll mn=inf,temp,pos,ch,pref=0;
    pbds A;
    fo(i,n){
        A.insert(i);
    }
    fo(i,n){
        ch = t[i]-'a';
        // deb2(i,ch);
        temp = inf;
        if(sgt.query(0,n-1,1,0,n-1)<ch){
            ll l=0,r=n-1,mid;
            pos=-1;
            while(l<=r){
                mid=(l+r)/2;
                if(sgt.query(0,n-1,1,l,mid)<ch){
                    pos=mid;
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            // deb(pos);
            temp= A.order_of_key(pos);
        }
        // deb2(temp,pref);
        mn=min(mn,temp+pref);
        if(mapp[ch].size() == 0){
            break;
        }
        else{
            pos = *mapp[ch].begin();
            mapp[ch].erase(pos);
            sgt.update(0,n-1,1,pos,30);
            pref+=A.order_of_key(pos);
            // deb2(pos,pref);
            A.erase(pos);
        }
    }
    if(mn==inf)mn=-1;
    cout<<mn<<nl;
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

