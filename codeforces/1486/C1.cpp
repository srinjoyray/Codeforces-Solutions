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
#define PI 3.141592653589793238
#define mod 1e9+7
int check(int l,int r){
    if(l>=r){
        return -1;
    }
    cout<<"? "<<l+1<<" "<<r+1<<endl;
    int ans;
    cin>>ans;
    return ans-1;
}
void solve(){
    int i,j;
    int n;
    cin>>n;
    int l=0,r=n,mid,smax;
    while(r-l>=2){
        mid=(l+r)/2;
        smax=check(l,r-1);
        if(smax<mid){
            if(check(l,mid-1)==smax){
                r=mid;
            }
            else{
                l=mid;
            }
        }
        else{
            if(check(mid,r-1)==smax){
                l=mid;
            }
            else{
                r=mid;
            }
        }
    }
    cout<<"! "<<r<<endl;
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

