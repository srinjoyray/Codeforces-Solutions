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
int spf[N];
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
void solve(){
    int i,j;
    int n,q;
    cin>>n>>q;
    int a[n],temp;
    fo(i,n){
        cin>>a[i];
    }
    vi adj(2e5,n);
    int up[n+1][20];
    fo(i,n+1){
        fo(j,20){
            up[i][j]=n;
        }
    }
    for(int i=n-1;i>=0;i--){
        up[i][0]=up[i+1][0];
        // deb2(i,a[i]);
        while(spf[a[i]]!=a[i]){
            temp=spf[a[i]];

            up[i][0]=min(adj[temp],up[i][0]);
            adj[temp]=i;

            // deb2(a[i],temp);
            
            while(a[i]%temp==0){
                a[i]/=temp;
            }
        }
        if(a[i]>1){
            // deb2(a[i],adj[i]);
            up[i][0]=min(adj[a[i]],up[i][0]);
            adj[a[i]]=i;
        }

    }
    // fo(i,n){
    //     cout<<up[i][0]<<" ";
    // }cout<<nl;
    for(j=1;j<20;j++){
        fo(i,n){
            up[i][j]=up[up[i][j-1]][j-1];
        }
    }

    while(q--){
        int l,r,ans=0;
        cin>>l>>r;
        l--,r--;
        for(j=19;j>=0;j--){
            if(up[l][j]<=r){
                l=up[l][j];
                ans+=(1<<j);
            }
        }
        cout<<ans+1<<nl;
    }
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t=1;
    // cin>>t;
    sieve();
    while(t--){
        solve();
    }
    
}

