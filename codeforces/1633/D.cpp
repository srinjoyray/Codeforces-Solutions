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

const int N=1e3+10;
const int M=2e4+10;

ll vis[N],val[N];
ll dp[N][M];
void solve(){
    int i,j;
    int n,k;
    cin>>n>>k;
    ll b[n],c[n],sum=0,mx=0;
    
    fo(i,n){
        // b[i]=1e3;
        cin>>b[i];
    }
    fo(i,n){
        // c[i]=1;
        cin>>c[i];
        sum+=c[i];
    }

    vpl v;
    fo(i,n){
        v.pb({val[b[i]],c[i]});
    }

    // fo(i,v.size()){
    //     cout<<v[i].F<<" "<<v[i].S<<nl;
    // }

    if(k>2*1e4){
        cout<<sum<<nl;
        return;
    }
    fo2(j,0,k){
        dp[0][j]=0;
    }
    fo2(i,1,n){
        fo2(j,0,k){
            
            if(j<v[i-1].F){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=max(dp[i-1][j], dp[i-1][j-v[i-1].F]+v[i-1].S);
            }
        }
    }
    // fo2(i,0,n){
    //     fo2(j,0,k){
    //         cout<<dp[i][j]<<" ";
    //     }cout<<nl;
    // }
    
    fo2(j,0,k){
        mx=max(mx,dp[n][j]);
    }
    cout<<mx<<nl;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll i,j,t=1,temp,new_val,mx=0;
    cin>>t;

    val[1]=0,vis[1]=0;
    queue<ll> q;
    q.push(1);
    while(!q.empty()){
        temp = q.front();
        q.pop();
        // deb(temp);
        fo2(j,1,temp){
            new_val = temp + temp/j;
            if(vis[new_val]==0 && new_val<N){
                vis[new_val]=1;
                val[new_val]=val[temp]+1;
                mx=max(mx,val[new_val]);
                q.push(new_val);
            }
        }
    }
    // deb(mx);
    while(t--){
        solve();
    }
    
}

