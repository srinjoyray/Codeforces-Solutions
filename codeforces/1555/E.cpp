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
const int INF = 1e9;
 
vector<int> t, ps;
 
void push(int v){
	if (v * 2 + 1 < int(ps.size())){
		ps[v * 2] += ps[v];
		ps[v * 2 + 1] += ps[v];
	}
	t[v] += ps[v];
	ps[v] = 0;
}

void upd(int v, int l, int r, int L, int R, int val){
	push(v);
	if (L >= R)
		return;
	if (l == L && r == R){
		ps[v] += val;
		push(v);
		return;
	}
	int m = (l + r) / 2;
	upd(v * 2, l, m, L, min(m, R), val);
	upd(v * 2 + 1, m, r, max(m, L), R, val);
	t[v] = min(t[v * 2], t[v * 2 + 1]);
}
int get(){
	return t[1] + ps[1];
}
struct seg{
	int l, r, w;
};
void solve(){
    int i,j;
    int n,m;
    cin>>n>>m;
    vector<seg> a(n);
    fo(i,n){
        cin>>a[i].l>>a[i].r>>a[i].w;
        a[i].l--;
        a[i].r--;
    }
    m--;
    sort(a.begin(), a.end(), [](const seg &a, const seg &b){
		return a.w < b.w;
	});
    
    t.resize(4 * m);
	ps.resize(4 * m);

    int ans = INF;
    j=0;
    fo(i,n){
        while (j < n && get() == 0){
			upd(1, 0, m, a[j].l, a[j].r, 1);
			++j;
		}
		if (get() == 0){
			break;
		}
		ans = min(ans, a[j - 1].w - a[i].w);
		upd(1, 0, m, a[i].l, a[i].r, -1);
    }
    cout<<ans<<nl;
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

