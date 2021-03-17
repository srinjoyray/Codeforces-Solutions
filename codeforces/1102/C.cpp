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

void solve(){
    int i,j;
    int n,x,y,count=0,count2=0,temp=0,save;
    cin>>n>>x>>y;
    int a[n];
    fo(i,n){
        cin>>a[i];
        if(a[i]<=x){
            count++;
        }
        if(a[i]<=x && a[i]+y>x){
            count2++;
        }
    }
    if(x>y){
        cout<<n<<nl;
        return;
    }
    save=min(count2,count/2);
    cout<<count-save<<nl;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

