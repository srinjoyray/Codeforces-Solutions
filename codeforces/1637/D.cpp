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
ll dp[N],dp2[N];
const ll inf =1e8;
void solve(){
    ll i,j;
    int n;
    cin>>n;
    ll a[n],b[n],ans=0,temp,mx=0,pref[n],sum,rem,sq=0,mn;
    
    fo(i,n){
        // a[i]=100;
        cin>>a[i];
        sq+=(a[i]*a[i]);
    }
    fo(i,n){
        // b[i]=100;
        cin>>b[i];
        sq+=(b[i]*b[i]);
    }
    if(n==1){
        cout<<"0\n";
        return;
    }
    // deb(sq);
    
    
    fo(i,n){
        pref[i]=a[i]+b[i];
        if(i>0){
            pref[i]+=pref[i-1];
        }
    }

    
    fo(i,N)dp[i]=inf;
    dp[a[0]]=0 , dp[b[0]]=0;
    
    vl v;
    set<int> se,s1;

    fo2(i,1,n-1){
        // deb2(i,pref[i-1]);
        se.clear();
        fo(j,N)dp2[j]=inf;
        for(j=pref[i-1];j>=1;j--){
            if(dp[j]==inf){
                continue;
            }
            // deb2(i,j);
            sum = pref[i-1];
            rem = sum-j;
            
            dp2[j+a[i]] = min(dp2[j+a[i]], dp[j]+a[i]*j + b[i]*rem);
            dp2[j+b[i]] = min(dp2[j+b[i]], dp[j]+b[i]*j + a[i]*rem);

            // if(i==2 && j==9){
            //     deb2(dp2[j+a[i]] , j+a[i]);
            //     deb2(dp2[j+b[i]] , j+b[i]);
            // }
            se.insert(j+a[i]);
            se.insert(j+b[i]);

            if(i==n-1)s1.insert(j+a[i]);
        }

        for(j=pref[i];j>=1;j--){
            if(se.find(j)==se.end()){
                dp[j]=inf;
            }
            else{
                dp[j]=dp2[j];
            }
        }

        // for(auto it : se){
        //     cout<<it<<"->"<<dp[it]<<nl;
        // }cout<<nl;
    }   
    
    mn=inf;
    
    for(auto it : s1){
        mn=min(mn,dp[it]);
    }

    // deb2(sq,mn);
    
    ans= sq*(n-1) + 2*mn ;
    // deb(ans);
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

