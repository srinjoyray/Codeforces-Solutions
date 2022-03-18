// #pragma GCC optimize(" unroll-loops")
// #pragma gcc optimize("Ofast")
// #pragma GCC optimization("Ofast")
// #pragma optimize(Ofast)

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

const int N=3e5+10;

void solve(){
    int i,j;
    int n,m;
    cin>>n>>m;
    vi a(n);

    set<pii> del;
    unordered_map<int,int> freq;
    unordered_map<int,vi> count;
    
    fo(i,n){
        cin>>a[i];
        freq[a[i]]++;
    }

    fo(i,m){
        int u,v;
        cin>>u>>v;
        del.insert(mp(u,v));
    }

    for(auto &x : freq){
        count[x.S].pb(x.F);
    }

    for(auto &it : count){
        sort(all(count[it.F]),greater<int>());
    }    

    ll ans=0;

    for(auto &it1 : count){
        for(auto &it2 : count){
            if(it1<it2)continue;
            for(auto &val1 : count[it1.F]){
                for(auto &val2 : count[it2.F]){
                    if(val1==val2 | del.find(mp(val1,val2))!=del.end() | del.find(mp(val2,val1))!=del.end()){
                        continue;
                    }
                    ans = max(ans,(ll)(it1.F+it2.F)*(ll)(val1+val2));
                    break;
                }
            }
        }
    }
    cout<<ans<<nl; 

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
