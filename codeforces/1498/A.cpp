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
#define tr(it,a) for(auto it=a.begin(); it!=a.end();it++)
#define nl '\n'
#define PI 3.141592653589793238
#define mod 1000000007
lli gcd(lli a,lli b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}
bool check(lli n){
    lli sum=0,temp=n,ans;
    while(temp){
        sum+=temp%10;
        temp/=10;
    }
    ans=gcd(sum,n);
    if(ans>1){
        return true;
    }
    return false;
}
void solve(){
    int i,j;
    lli n;
    cin>>n;
    bool flag=true;
    while(flag){
        if(check(n)){
            flag=false;
            break;
        }
        n++;
    }
    cout<<n<<nl;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

