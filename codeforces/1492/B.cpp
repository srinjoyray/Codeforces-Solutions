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
    int p[n],pos[n+1],mx=0,temp,last,start,copy,prefix[n]={0};
    vector<int> order;
    fo(i,n){
        cin>>p[i];
        pos[p[i]]=i;
    }
    fo(i,n){
        mx=max(mx,p[i]);
        prefix[i]=mx;
    }
    copy=n;
    i=0;
    while(i<n){
        mx=prefix[n-1];
        temp=pos[mx];
        n=temp;
        order.pb(temp);
        // deb(copy);
    }
    n=copy;
    fo(i,order.size()){
        // cout<<order[i]<<" ";
    }
    // cout<<endl;
    last=n;
    fo(i,order.size()){
        start=order[i];
        // deb2(start,last);
        for(j=start;j<last;j++){
            cout<<p[j]<<" ";
        }
        last=start;
    }
    cout<<endl;
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

