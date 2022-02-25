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
struct Segtree {
	vector<pl> tree;
    vector<pl> lazy;
	int n;
	Segtree(int a_len) { // change if type updated
		n = a_len;
		tree.resize(4 * n);
		lazy.resize(4 * n); 
        for(int i=0;i<tree.size();i++)tree[i]={0,-1};
        for(int i=0;i<lazy.size();i++)lazy[i]={0,-1};
	}
	
    void push(int index,int start,int end)
    {  
        if (start != end)
        {
            if(lazy[index].F>lazy[2 * index].F) lazy[2 * index] = lazy[index];
            if(lazy[index].F>lazy[2 * index + 1].F) lazy[2 * index + 1] = lazy[index];
        }
        lazy[index] = {0,-1};
    }
	void update(int start, int end, int index, int start_range, int end_range, pl val)  
	{
		if (start > end)
            return;
        
        if(lazy[index].F > tree[index].F) tree[index] = lazy[index] ;
        push(index,start,end);
 
        if (start_range > end || end_range < start) //no overlap
            return;
        if (start_range <= start && end_range >= end) //complete overlap
        {
            if(val.F > tree[index].F) tree[index] = val ;
            if(val.F > lazy[index].F) lazy[index] = val ;
            
            push(index,start,end);
 
            return;
        }
        int mid = (start + end) / 2;
        update(start, mid, 2 * index, start_range, end_range, val);
        update(mid + 1, end, 2 * index + 1, start_range, end_range, val);

        if(tree[2 * index].F >= tree[2 * index + 1].F) tree[index] = tree[2 * index] ;
        else tree[index] = tree[2 * index + 1] ;
	}
	pl query(int start, int end, int index, int left, int right) 
    { 
		if (start > end)
            return {0,-1};
        if (lazy[index].F != 0)
        {
            if(lazy[index].F > tree[index].F) tree[index] = lazy[index] ;
            push(index,start,end);
        }
        if (start > right || end < left)
            return {0,-1};
        if (start >= left && end <= right)
            return tree[index];
		int mid = (start + end) / 2;
		pl l, r, ans;
		l = query(start, mid, 2 * index, left, right);
		r = query(mid + 1, end, 2 * index + 1, left, right);
		ans= l.F>= r.F ? l : r;
		return ans;
	}
};
void solve(){
    int i,j;
    int n,m;
    cin>>n>>m;
    vpl adj[n+1];
    set<ll> se;
    fo(j,m){
        ll l,r;
        cin>>i>>l>>r;
        
        adj[i].pb({l,r});
        se.insert(l);
        se.insert(r);
        
    }
    map<ll,ll> comp;
    ll count=1,sz;
    for(auto it :  se){
        comp[it] = count++;
    }
    sz=count+10;
    Segtree sgt(sz);

    ll mx=0,l,r,pos;
    pl query,dp[n+1];
    vl v;
    dp[0]={0,0};
    fo2(i,1,n){
        // deb(i);
        for(j=0;j<adj[i].size();j++){
            l=comp[adj[i][j].F];
            r=comp[adj[i][j].S];
            // deb2(l,r);
            query = sgt.query(0,sz-1,1,l,r);
            // deb2(query.F,query.S);
            if(query.F+1>=dp[i].F){
                dp[i]={query.F+1,query.S};
            }
        }
        for(j=0;j<adj[i].size();j++){
            l=comp[adj[i][j].F];
            r=comp[adj[i][j].S];
            sgt.update(0,sz-1,1,l,r,{dp[i].F,i}); 
        }
        // deb2(dp[i].F,dp[i].S);
        
    }
    fo2(i,1,n){
        mx=max(mx,dp[i].F);
    }
    fo2(i,1,n){
        if(dp[i].F==mx){
            pos=i;
        }
    }
    set<ll> in;

    while(pos>0){
        in.insert(pos);
        pos=dp[pos].S;
    }
    // deb(mx);
    cout<<n-mx<<nl; 
    fo2(i,1,n){
        if(in.find(i)==in.end()){
            cout<<i<<" ";
        }
    }
    cout<<nl;
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

