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
#define mod 998244353

typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

const int N=2e5+10;
ll fact[N];
ll power(ll a,ll n){
    ll res=1;
    while(n){
        if(n%2){
            res=(res*a)%mod;
        }
        a=(a*a)%mod;
        n/=2;
    }
    return res;
}
struct Segtree {
	vector<ll> tree;
	vector<ll> arr; // type may change
	int n;
	Segtree(int a_len) { // change if type updated
		n = a_len;
		tree.resize(4 * n); fill(all(tree), 0);
	}
	
	void update(int start, int end, int index, int query_index, ll val)  
	{
		if (start == end) {
			tree[index] += val;
			return;
		}
		int mid = (start + end) / 2;
		if (mid >= query_index)
			update(start, mid, 2 * index, query_index, val);
		else
			update(mid + 1, end, 2 * index + 1, query_index, val);
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
    int n,m;
    cin>>n>>m;
    int s[n],t[m];
    fo(i,n){
        // s[i]=i%2+1;
        cin>>s[i];
    }
    fo(i,m){
        // t[i]=1+(i+1)%2;
        cin>>t[i];
    }
    int sz = N;
    Segtree sgt(sz);
    map<ll,ll> freq;
    fo(i,n){
        sgt.update(0,sz-1,1,s[i],1);
        freq[s[i]]++;
    }

    ll denom = 1,val,temp,inv_denom,ans=0;
    for(auto it : freq){
        denom = (denom*fact[it.S])%mod;
    }

    fo(i,m){
        if(i>=n){
            ans = (ans+1)%mod;
            break;
        }
        val = sgt.query(0,sz-1,1,0,t[i]-1);
        inv_denom = power(denom,mod-2);
        temp = (fact[n-i-1]*val)%mod;
        // deb(temp);
        temp = (temp*inv_denom)%mod;
        // deb2(val,temp);
        ans = (ans+temp)%mod;

        if(freq[t[i]]==0){
            break;
        }
        sgt.update(0,sz-1,1,t[i],-1);
        denom = (denom*power(freq[t[i]],mod-2))%mod;
        freq[t[i]]--;
        
    }
    cout<<ans<<nl;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t=1;
    // cin>>t;
    fact[0]=1;
    for(int i=1;i<N;i++){
        fact[i] = (fact[i-1]*i)%mod;
    }
    while(t--){
        solve();
    }
    
}

