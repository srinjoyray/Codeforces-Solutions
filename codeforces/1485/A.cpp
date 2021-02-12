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
#define tr(it,a) for(auto it=a.begin(); it!=a.end();it++)
#define PI 3.141592653589793238
#define mod 1e9+7

void solve(){
    int i,j;
    lli a,b,count=0,temp,ans,temp_b,temp_a;
    cin>>a>>b;
    if(b==1){
        temp_b=2;
        count=1;
    }
    else{
        temp_b=b;
    }
    temp_a=a;
    while(temp_a){
        temp_a=temp_a/temp_b;
        count++;
        // deb2(a,count);
    }
    ans=count;
    fo2(i,1,count){
        temp=i;
        temp_b=b+i;
        temp_a=a;
        while(temp_a){
            temp_a/=temp_b;
            temp++;
        }
        // deb2(temp_b,temp);

        ans=std::min(ans,temp);
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

