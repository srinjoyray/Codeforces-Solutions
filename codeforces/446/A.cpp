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
    int n;
    cin>>n;
    lli a[n];
    fo(i,n){
        cin>>a[i];
        // deb(a[i]);
    }
    lli l[n+1]={0},r[n+1]={0},temp,ans=2;
    if(n<=2){
        cout<<n<<nl;
        return;
    }
    temp=1; l[0]=1;
    fo2(i,1,n-1){
        if(a[i]>a[i-1]){
            temp++;
        }
        else{
            temp=1;
        }
        l[i]=temp;
        // deb2(i,l[i]);
    }
    temp=1;
    r[n-1]=1;
    for(j=n-2;j>=0;j--){
        if(a[j]<a[j+1]){
            temp++;
        }
        else{
            temp=1;
        }
        r[j]=temp;
        // deb2(j,r[j]);
    }
    fo2(i,1,n-2){
        if(a[i+1]>a[i-1]+1){
            temp=l[i-1]+r[i+1]+1;
        }
        else{
            temp=max(l[i-1],r[i+1])+1;
        }
        // deb2(i,temp);
        ans=max(ans,temp);
    }
    temp=l[n-2]+1;
    ans=max(ans,temp);
    temp=r[1]+1;
    ans=max(ans,temp);
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
}

