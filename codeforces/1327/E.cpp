#include<bits/stdc++.h>
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define fo2(i,start,end) for(i=start;i<=end;i++)
#define rfo(i,n) for(i=n-1;i>=0;i--)
#define lli long long int
#define deb(x) cout<<#x<<"="<<x<<endl
#define deb2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
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
typedef pair<lli, lli>	pl;
typedef vector<int>		vi;
typedef vector<lli>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
lli power(lli a,lli n){
    lli res=1;
    while(n){
        if(n%2){
            res=(res*a)%mod;
        }
        a=(a*a)%mod;
        n/=2;
    }
    return res;
}
void solve(){
    int i,j;
    lli n,total,prev=0,sum=0,rem,val;
    vl v;
    cin>>n;
    for(i=1;i<=n;i++){
        total=(i*power(10,i))%mod;
        rem=(total-(sum+prev))%mod;
        rem%=mod;
        while(rem<0){
            rem+=mod;
        }
        // deb2(total,rem);
        v.pb(rem);
        // deb2(prev,sum);
        if(i==4){
            // deb2(total,rem);
            // deb2(sum,prev);
        }
        sum+=rem;
        prev=total;
        sum%=mod;
        prev%=mod;
    }
    reverse(all(v));
    fo(i,n){
        cout<<v[i]<<" ";
    }cout<<nl;
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

