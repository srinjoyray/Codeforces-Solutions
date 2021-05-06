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
lli power(lli a,lli n){
    lli res=1;
    while(n){
        if(n%2==1){
            res*=a;
            res%=mod;
        }
        a*=a;
        a%=mod;
        n/=2;
    }
    return res;
}
void solve(){
    int i,j;
    string s;
    cin>>s;
    lli n; 
    n=s.size();
    lli ans=0,left[n+1]={0},right[n+1]={0},con,temp,dig,store=0;
    
    j=0;
    con=(j+1)*power(10,j);
    store+=con;
    for(i=n-2;i>=0;i--){
        // deb2(store,con);
        dig=s[i]-'0';
        temp=store*dig;
        right[i+1]=temp;
        right[i+1]%=mod;
        j++;
        con=(j+1)*power(10,j);
        store+=con;
        store%=mod;
        con%=mod;
    }
    con=1;
    store=1;
    for(i=1;i<n;i++){
        j=n-i-1;
        dig=s[i]-'0';
        temp=store*power(10,j)*dig;
        left[i+1]=temp;
        left[i+1]%=mod;
        con++;
        store+=con;
        store%=mod;
        con%=mod;
    }
    fo2(i,1,n){
        ans+=left[i]+right[i];
        // deb2(left[i],right[i]);
        ans%=mod;
    }
    cout<<ans<<nl;
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

