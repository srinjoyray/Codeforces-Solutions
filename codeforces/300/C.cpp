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
#define mod 1000000007
typedef pair<int, int>	pii;
typedef pair<lli, lli>	pl;
typedef vector<int>		vi;
typedef vector<lli>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
lli fact[10000000];
lli power(lli x,lli n){
    lli res=1;
    while(n){
        if(n%2==1){
            res*=x;
            res%=mod;
            n--;
        }
        else{
            x*=x;
            x%=mod;
            n/=2;
        }
    }
    return res;
}
lli ncr(lli n,lli r){
    lli num,denom,ans;
    num=fact[n];
    denom=(fact[r]*fact[n-r])%mod;
    denom=power(denom,mod-2);
    ans=(num*denom)%mod;
    return ans;
}
bool check(lli a,lli b,lli num){
    lli dig;
    // deb(num);
    while(num){
        dig=num%10;
        if(dig!=a && dig!=b){
            return false;
        }
        num/=10;
    }
    return true;
}
void solve(){
    lli i,j;
    lli a,b;
    cin>>a>>b;
    lli n,temp,ans=0;
    cin>>n;
    // deb(n);
    for(i=0;i<=n;i++){
        temp=(i*a)+(n-i)*b;
        if(check(a,b,temp)){
            ans+=ncr(n,i);
            ans%=mod;
        }     
    }
    cout<<ans<<nl;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t=1;
    lli i;
    fact[0]=1;fact[1]=1;
    for(i=2;i<10000000;i++){
        fact[i]=(fact[i-1]*i)%mod;
    }
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

