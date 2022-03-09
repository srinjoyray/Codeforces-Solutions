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
#define mod 1000000007

typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

const int N=1e5+10;
const ll inf = 1e12;
ll dp[N][110];
struct task{
    ll e,t,p;
};
struct node{
    ll t,p,index;
    void form(ll t1,ll p1,ll i){
        t = t1;
        p = p1;
        index = i;
    }
};
bool comp(node a,node b){
    return a.p<=b.p;
}
vl helper(vector<node>v,ll rem){
    // sort(all(v),comp);
    ll i,j,n;
    n=v.size();
    vl ans;
    // fo(i,v.size()){
    //     cerr<<v[i].p<<" "<<v[i].t<<nl;
    // }
    ll temp,curr;

    fo2(i,0,n){
        fo(j,101){
            dp[i][j]=inf;
        }
        dp[i][0]=0;
    }

    fo(i,n){
        for(j=0;j<=100;j++){
            dp[i+1][j] = min(dp[i][j],dp[i+1][j]);
            temp = min(j+v[i].p,1LL*100);    
            
            dp[i+1][temp] = min({dp[i][j]+v[i].t , dp[i][temp] , dp[i+1][temp]});
            if(dp[i+1][temp]<inf){
                // deb2(temp,dp[i+1][temp]);
            }
        }
        // deb2(dp[i+1][100],dp[i+1][38]);
    }
    deb(dp[n][100]);
    if(dp[n][100]>rem){
        return ans;
    }
    curr=100;
    for(i=n;i>0;i--){
        if(dp[i-1][curr]!=dp[i][curr]){
            ans.pb(v[i-1].index);
            ll start = max(0LL,curr-v[i-1].p);
            fo2(j,start,curr){
                if(dp[i-1][j]+v[i-1].t == dp[i][curr]){
                    curr=j;
                    break;
                }
            }
        }
    }
    // deb(ans.size());
    return ans;
}
void solve(){
    int i,j;
    int n,m;
    cin>>n>>m;
    ll a[n];
    fo(i,n){
        cin>>a[i];
    }
    vpl vp;
    fo(i,n){
        vp.pb({a[i],i+1});
    }
    sort(all(vp));
    
    vector<task> v(m);
    vector<node> b[n+1];
    fo(i,m){
        cin>>v[i].e>>v[i].t>>v[i].p;
        struct node n1;
        n1.form(v[i].t,v[i].p,i);
        b[v[i].e].pb(n1);
    }
    ll done=0,rem;
    vector<vl> ans;
    fo(i,vp.size()){
        int idx = vp[i].S;
        vl v_temp;
        rem = vp[i].F-done;
        deb(idx);
        v_temp = helper(b[idx],rem);
        if(v_temp.size()==0){
            cout<<"-1\n";
            return;
        }
        ans.pb(v_temp);
        fo(j,v_temp.size()){
            done+=v[v_temp[j]].t;
        }
    }

    ll count=0;
    fo(i,ans.size()){
        fo(j,ans[i].size()){
            count++;
        }
    }
    cout<<count<<nl;
    fo(i,ans.size()){
        fo(j,ans[i].size()){
            cout<<ans[i][j]+1<<" ";
        }
    }
    cout<<nl;

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

