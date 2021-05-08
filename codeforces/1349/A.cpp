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
lli lcm(lli a,lli b){
    lli gcd,res;
    gcd=__gcd(a,b);
    res=(a*b)/gcd;
    return res;
}
void solve(){
    int i,j;
    int n;
    cin>>n;
    lli a[n],pref[n+1]={0},suff[n+1]={0},temp,gcd[n+1],ans;
    fo(i,n){
        cin>>a[i];
    }
    pref[1]=a[0];
    temp=a[0];
    fo2(i,1,n-1){
        temp=__gcd(temp,a[i]);
        pref[i+1]=temp;
    }
    suff[n]=a[n-1];
    temp=a[n-1];
    for(i=n-2;i>=0;i--){
        temp=__gcd(temp,a[i]);
        suff[i+1]=temp;
    }
    fo2(i,1,n){
        if(i==1){
            gcd[i]=suff[i+1];
        }
        else if(i==n){
            gcd[i]=pref[i-1];
        }
        else{
            gcd[i]=__gcd(pref[i-1],suff[i+1]);
        }
    }
    /*fo2(i,1,n){
        cout<<gcd[i]<<" ";
    }cout<<nl;*/
    ans=gcd[1];
    fo2(i,2,n){
        ans=lcm(ans,gcd[i]);
    }
    cout<<ans;
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
    return 0;
}

