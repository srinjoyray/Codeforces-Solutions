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
#define mod 1e9+7
void solve(){
    int i,j;
    int n,U,R,D,L,temp1,temp2;
    cin>>n>>U>>R>>D>>L;
    temp1=L;
    temp2=R;
    if(U==n){
        temp1--;
        temp2--;
    }
    else if(U==n-1){
        if(temp1>temp2){
            temp1--;
        }
        else{
            temp2--;
        }
    }
    if(D==n){
        temp1--;
        temp2--;
    }
    else if(D==n-1){
        if(temp1>temp2){
            temp1--;
        }
        else{
            temp2--;
        }
    }
    if(temp1<0 || temp2<0){
        cout<<"NO\n";
        return;
    }
    temp1=U;
    temp2=D;
    if(L==n){
        temp1--;
        temp2--;
    }
    else if(L==n-1){
        if(temp1>temp2){
            temp1--;
        }
        else{
            temp2--;
        }
    }
    if(R==n){
        temp1--;
        temp2--;
    }
    else if(R==n-1){
        if(temp1>temp2){
            temp1--;
        }
        else{
            temp2--;
        }
    }
    if(temp1<0 || temp2<0){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";

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

