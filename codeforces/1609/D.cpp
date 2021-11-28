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
void solve(){
    int i,j;
    int n,q;
    cin>>n>>q;
    UnionFind u(n);
    ll mx=1,temp;
    ll dp[n],extra=1;
    set<pl> se;
    fo(i,n){
        dp[i]=1;
        se.insert({1,i});
    }
    while(q--){
        int a,b,p1,p2,p3;
        vi v;
        cin>>a>>b;
        a--,b--;
        // deb2(a,b);
        p1=u.get(a);
        p2=u.get(b);
        // deb2(p1,p2);
        // deb2(dp[p1],dp[p2]);
        
        if(p1==p2){
            extra++;
            for(auto it : se){
                v.pb(it.F);
            }
            sort(all(v),greater<ll>());
            temp=0;
            fo(i,v.size()){
                if(i>=extra){
                    break;
                }
                temp+=v[i];
            }
            cout<<temp-1<<nl;
            continue;
        }
        se.erase(se.find({dp[p1],p1}));
        se.erase(se.find({dp[p2],p2}));

        u.merge(a,b);

        p3=u.get(a);
        
        
        if(p3==p1){
            dp[p1]+=dp[p2];
        }
        else{
            dp[p2]+=dp[p1];
            
        }
        se.insert({dp[p3],p3});
        // deb2(p3,dp[p3]);

        for(auto it : se){
            v.pb(it.F);
        }
        sort(all(v),greater<ll>());
        temp=0;
        fo(i,v.size()){
            if(i>=extra){
                break;
            }
            temp+=v[i];
        }
        cout<<temp-1<<nl;
       
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

