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
    int i,j,l,r;
    string a,b;
    int len1,len2,temp,mx=0,ans;
    cin>>a>>b;
    len1=a.size();
    len2=b.size();
    fo(i,len1){
        fo(j,len2){
            l=i;
            r=j;
            while(a[l]==b[r] && l<len1 && r<len2){
                l++;
                r++;
            }
            temp=l-i;
            mx=max(mx,temp);
        }
    }
    ans=len1+len2-(2*mx);
    // deb2(a,b);
    // deb(mx);
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

