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
void solve(){
    int i,j;
    lli r,g,b,a[3],sum=0,mx;
    cin>>r>>g>>b;
    a[0]=r; a[1]=g; a[2]=b;
    sort(a,a+3,greater<lli>());
    fo(i,3){
        sum+=a[i];
    }
    if(sum%3==2){
        a[0]--;
        if(a[0]>a[1]){
            a[0]--;
        }
        else{
            a[1]--;
        }
    }
    else if(sum%3==1){
        a[0]--;
    }
    sum-=sum%3;
    sort(a,a+3,greater<lli>());
    mx=(a[1]+a[2])*2;
    if(a[0]>mx){
        sum-=a[0]-mx;
    }
    sum/=3;
    cout<<sum<<nl;
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

