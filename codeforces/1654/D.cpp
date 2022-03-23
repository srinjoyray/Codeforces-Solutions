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

const int N=1e6+10;
vector<pair<ll,pl>> adj[N];
ll spf[N];
vl val(N),curr(N),highest(N);
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
void sieve()
{
    spf[1] = 1;
    for (int i=2; i<N; i++)
        spf[i] = i;

    for (int i=4; i<N; i+=2)
        spf[i] = 2;
 
    for (int i=3; i*i<N; i++){
        if (spf[i] == i){
            for (int j=i*i; j<N; j+=i)
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}
vpl factors(ll num){
    vpl v;
    while(num>1){
        ll pf = spf[num] , count = 0 ;
        while(num%pf == 0){
            count++;
            num/=pf;
        }
        v.pb({pf,count});
    }
    return v;
}
ll inv(ll num){
    return power(num,mod-2);
}

void dfs(int node,int parent){
    ll num,denom,gcd;
    for(auto it : adj[node]){
        int child = it.F;
        if(child != parent){
            ll x = it.S.F ,  y = it.S.S , temp;
            vpl v1 = factors(x);
            vpl v2 = factors(y);
            temp = (y*inv(x))%mod;
            val[child] = (val[node]*temp)%mod;

            for(auto it : v2){
                curr[it.F] -= it.S;
            }
            for(auto it : v1){
                curr[it.F] += it.S;
                highest[it.F] = max(highest[it.F] , curr[it.F]);
            }

            dfs(child,node);

            for(auto it : v2){
                curr[it.F] += it.S;
            }
            for(auto it : v1){
                curr[it.F] -= it.S;
            }
        }
    }
}
void solve(){
    int i,j;
    ll n,temp,lcm=1,count,ans=0,sum=0;
    cin>>n;
    fo2(i,1,n){
        adj[i].clear();
        highest[i]=0;
        curr[i]=0;
    }
    fo(i,n-1){
        int u,v,x,y;
        cin>>u>>v>>x>>y;
        adj[u].pb({v,{x,y}});
        adj[v].pb({u,{y,x}});
    }

    val[1]=1;
    dfs(1,-1);

   
    fo2(i,1,n){
        temp = power(i,highest[i]);
        lcm = (lcm*temp)%mod;
    }
    
    fo2(i,1,n){
        sum = (sum+val[i])%mod;
    }

    ans = (sum*lcm)%mod;
    cout<<ans<<nl;

}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t=1;
    cin>>t;
    sieve();
    while(t--){
        solve();
    }
    
}

