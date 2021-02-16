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

void solve(){
    int i,j;
    lli n,k,ans,gap,total,full,rem,pos;
    cin>>n>>k;
    if(n%2==0){
        ans=k%n;
        if(ans==0){
            ans=n;
        }
        cout<<ans<<endl;
        return ;
    }
    k--;
    gap=(n-1)/2;
    total=(gap-1)+2;
    // deb(total);
    full=k/gap;
    rem=k%gap;
    // deb2(full,rem);
    pos=1+full*(total);
    pos+=rem;
    pos=pos%n;
    if(pos==0){
        pos=n;
    }
    cout<<pos<<endl;

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

