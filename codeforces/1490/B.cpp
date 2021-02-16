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
    int n;
    cin>>n;
    int a[n],zero=0,one=0,two=0,ans=0,req,count=0;
    fo(i,n){
        cin>>a[i];
    }
    fo(i,n){
        if(a[i]%3==0){
            zero++;
        }
        else if(a[i]%3==1){
            one++;
        }
        else{
            two++;
        }
    }
    req=n/3;
    if(zero>=req){
        one+=zero-req;
        count+=zero-req;
        if(one>=req){
            two+=one-req;
            count+=one-req;
        }
        else{
            count+=2*(req-one);
        }
    }
    else if(one>=req){
        two+=one-req;
        count+=one-req;
        if(two>=req){
            count+=two-req;
        }
        else{
            count+=2*(req-two);
        }
    }
    else if(two>=req){
        zero+=two-req;
        count+=two-req;
        if(zero>=req){
            count+=zero-req;
        }
        else{
            count+=2*(req-zero);
        }
    }
    cout<<count<<endl;


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

