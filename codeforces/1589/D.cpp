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
ll ask(ll i,ll j){
    ll x;
    cout<<"? "<<i<<" "<<j<<endl;
    cin>>x;
    return x;
}
ll find(ll num,ll n){
    ll ans=0,low=1,high=n,mid;
    while(low<=high){
        mid=(low+high)/2;
        if((mid*(mid+1))/2<=num){
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
   
    return ans;
}
void solve(){
    int i,j,k;
    ll n;
    cin>>n;
 
    ll low,high,mid,start=0,x,total,ans=0,len1,len2,rem;
    low=1,high=n;
    while(low<=high){
        mid=(low+high)/2;
        x=ask(1,mid);
        if(x==0){
            start=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    total=ask(1,n);
    // deb(start);
    
    len1=total-ask(start+1,n);

    rem=total-(len1*(len1+1)/2);

    len2=find(rem,n);

    // deb2(len1,len2);

    i=start;
    j=start+len1+1;
    k=j+len2;

    cout<<"! "<<i<<" "<<j<<" "<<k<<endl;
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

