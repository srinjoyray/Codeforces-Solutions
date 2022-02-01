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
ll p[N],x,y,a,b,k;
bool check(ll mid){
    ll lcm,count1,count2,count_both,i,j,sum=0;
    lcm = (a*b)/__gcd(a,b);
    count_both = mid/lcm;
    count1 = mid/a - count_both;
    count2 = mid/b - count_both;

    // deb(count_both);
    // deb2(count1,count2);

    fo(i,count_both){
        sum+=(x+y)*p[i];
    }

    if(x>=y){
        i=count_both;
        fo(j,count1){
            sum+=x*p[i];
            i++;
        }
        fo(j,count2){
            sum+=y*p[i];
            i++;
        }
    }
    else{
        i=count_both;
        fo(j,count2){
            sum+=y*p[i];
            i++;
        }
        fo(j,count1){
            sum+=x*p[i];
            i++;
        }
    }
    if(sum>=k){
        return true;
    }
    return false;
}
void solve(){
    int i,j;
    int n;
    cin>>n;
    fo(i,n){
        cin>>p[i];
        p[i]/=100;
    }
    cin>>x>>a;
    cin>>y>>b;
    cin>>k;

    sort(p,p+n,greater<ll>());

    ll low=1,high = n, ans=n+1, mid;
    while(low<=high){
        mid=(low+high)/2;
        if(check(mid)){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    if(ans>n){
        ans=-1;
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

