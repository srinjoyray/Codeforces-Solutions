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
const int N=1e6+10;
// Range sum queries
struct SegTree {
	vector<ll> tree;
	vector<ll> arr; // type may change
	int n;
	SegTree(int a_len, vector<ll> &a) { // change if type updated
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
		tree[index]=(tree[2 * index] + tree[2 * index + 1]);
	}
	
	ll query(int start, int end, int index, int left, int right) { 
		if (start > right || end < left)
			return 0;
		if (start >= left && end <= right)
			return tree[index];
		int mid = (start + end) / 2;
		ll l, r, ans;
		l = query(start, mid, 2 * index, left, right);
		r = query(mid + 1, end, 2 * index + 1, left, right);
		ans=(l+r);
		return ans;
	}
};
void solve(){
    int i,j;
    int n,q;
    cin>>n>>q;
    string s;
    vl v;
    cin>>s;
    fo(i,n){

       if(s[i]=='+'){
           if(i%2==0){
               v.pb(1);
           }
           else{
               v.pb(-1);
           }
       }
       else{
           if(i%2==1){
               v.pb(1);
           }
           else{
               v.pb(-1);
           }
       }
    }
    // deb2(even,odd);
    SegTree seg(v.size(),v);
    

    while(q--){
        int l,r,temp;
        cin>>l>>r;
        l--; r--;
        temp=seg.query(0,n-1,1,l,r);
        if(temp==0){
            cout<<"0\n";
        }
        else if((r-l+1)%2==1){
            cout<<"1\n";
        }else{
            cout<<"2\n";
        }
        // cout<<abs(pos-neg)<<nl;
    }
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

