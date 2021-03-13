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
    int n;
    cin>>n;
    lli a[n],b[n],t[n],dur[n],count=0;
    fo(i,n){
        cin>>a[i]>>b[i];
        dur[i]=(b[i]-a[i]+1)/2;
    }
    fo(i,n){
        cin>>t[i];
    }
    fo(i,n){
        if(i==0){
            count=a[i]+t[i];
        }
        else{
            count=count+a[i]-b[i-1]+t[i];
        }
        // deb2(i,count);
        if(i==n-1){
            cout<<count<<nl;
            return;
        }
        count=max(count+dur[i],b[i]);
        // deb(count);
    }

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

