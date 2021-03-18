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
    int n,right=0,up=0,no_r,no_u,val_r,val_u;
    cin>>n;
    lli c[n],ans,temp,mn;
    fo(i,n){
        cin>>c[i];
    }
    ans=(c[0]+c[1])*n;
    no_r=n;
    no_u=n;
    val_r=c[0];
    val_u=c[1];
    mn=ans;
    for(i=2;i<n;i++){
        if(c[i]<val_r){
            no_r--;
            ans-=no_r*(val_r-c[i]);
            val_r=c[i];
        }
        else{
            no_r--;
            ans=ans+c[i]-val_r;
        }
        mn=min(mn,ans);
        i++;
        if(i<n){
            if(c[i]<val_u){
                no_u--;
                ans-=no_u*(val_u-c[i]);
                val_u=c[i];
            }
            else{
                no_u--;
                ans+=c[i]-val_u;
            }
        }
        mn=min(mn,ans);
    }
    cout<<mn<<nl;
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

