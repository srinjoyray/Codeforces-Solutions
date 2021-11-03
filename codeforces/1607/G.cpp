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

void solve(){
    int i,j;
    ll n,m;
    cin>>n>>m;
    ll a[n],b[n],c[n],l=0,r=0,sum=0,ans,done=0,temp;
    fo(i,n){
        cin>>a[i]>>b[i];
    }
    fo(i,n){
        // deb2(a[i],b[i]);
        l+=max((ll)0,m-b[i]);
        r+=min(a[i],m);
        // deb2(l,r);
        sum+=(a[i]-b[i]);
        c[i]=max((ll)0,m-b[i]);
        done+=c[i];
    }
    // fo(i,n){
    //     cout<<c[i]<<" ";
    // }cout<<nl;
    sum+=n*m;
    // deb(sum);
    if(2*l<=sum && sum<=2*r){
        ans=sum/2;
    }
    else{
        if(abs(sum-2*l)<=abs(sum-2*r)){
            ans=l;
        }
        else{
            ans=r;
        }
    }
    cout<<abs(sum-2*ans)<<nl;
    // deb2(ans,done);
    // a-b+m-2k
    fo(i,n){
        r=min(a[i],m);
        temp=min(ans-done,r-c[i]);
        temp=max(temp,(ll)0);
        done+=temp;
        c[i]+=temp;
        // deb2(temp,c[i]);
        if(done==ans){
            break;
        }
        
    }
    // cout<<ans<<nl;
    fo(i,n){
        cout<<c[i]<<" "<<m-c[i]<<nl;
    }
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

