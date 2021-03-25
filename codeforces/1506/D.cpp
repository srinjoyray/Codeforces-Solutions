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
    lli i,j;
    lli n;
    cin>>n;
    lli a[n],temp,mx=0,rem,ans;
    fo(i,n){
        cin>>a[i];
    }
    sort(a,a+n);
    for(i=0;i<n;i++){
        j=i+1;
        while(j<n && a[i]==a[j]){
            j++;
        }
        temp=j-i;
        i=j-1;
        mx=max(mx,temp);
    }
    // deb(mx);
    rem=n-mx;
    if(rem>=mx){
        ans=n%2;
    }
    else{
        ans=mx-rem;
    }
    cout<<ans<<endl;

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

