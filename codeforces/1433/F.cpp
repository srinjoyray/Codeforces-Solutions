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

const int N=1e6+10,inf=1e6;
int dp[80][5000],mat[80][80];
vi states(vi v){
    int i,j,n=v.size();
    fo(i,n+1){
        fo(j,5000){
            dp[i][j]=inf;
        }
    }
    fo(i,n){
        dp[i][0]=0;
    }
    fo2(i,1,n){
        // deb(v[i-1]);
        fo(j,5000){
            if(v[i-1]<=j){
               
                dp[i][j]=min(dp[i-1][j],dp[i-1][j-v[i-1]]+1);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
            // deb2(j,dp[i][j]);
        }
    }
    vi ans;
    fo2(j,1,4999){
        if(dp[n][j]<=n/2){
            ans.pb(j);
        }
    }
    // fo2(j,0,10){
    //     cout<<dp[n][j]<<" ";
    // }cout<<nl;
    return ans;
}
void solve(){
    int i,j,j1;
    int n,m,k,val;
    cin>>n>>m>>k;
    vector<vi> v(n);
    fo(i,n){
        vi v1(m);
        fo(j,m){
            cin>>v1[j];
        }
        v[i]=states(v1);
        // fo(j,v[i].size()){
        //     cout<<v[i][j]<<" ";
        // }cout<<nl;
    }

    memset(mat,-1,sizeof mat);
    fo2(i,0,n){
        mat[i][0]=0;
    }
    
    // fo2(i,0,n){
    //     fo(j,k){
    //         cout<<mat[i][j]<<" ";
    //     }cout<<nl;
    // }
    fo2(i,1,n){
        fo(j1,k){
            if(mat[i-1][j1]==-1){
                continue;
            }
            mat[i][j1]=max(mat[i][j1],mat[i-1][j1]);
            fo(j,v[i-1].size()){
                val=(j1+v[i-1][j])%k;
                // deb2(v[i-1][j],val);
                mat[i][val]=max(mat[i][val],mat[i-1][j1]+v[i-1][j]);
                // deb2(i,mat[i][val]);
            }
        }
    }

    // fo2(i,0,n){
    //     fo(j,k){
    //         cout<<mat[i][j]<<" ";
    //     }cout<<nl;
    // }
    if(mat[n][0]!=-1){
        cout<<mat[n][0]<<nl;
    }else{
        cout<<"0\n";
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

