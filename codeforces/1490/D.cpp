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
int ans[101];
int n;
void func(int a[],int start,int end,int val){
    int mx=-1,pos,i,j;
    // deb2(start,end);
    if((start>end)||(start>=n)||(end<0)){
        return;
    }
    fo2(i,start,end){
        if(a[i]>mx){
            mx=a[i];
            pos=i;
        }
    }
    ans[pos]=val;
    func(a,start,pos-1,val+1);
    func(a,pos+1,end,val+1);
}

void solve(){
    int i,j;
    
    cin>>n;
    int a[n];
    fo(i,n){
        cin>>a[i];
        
    }
    
    func(a,0,n-1,0);
   
    fo(i,n){
        cout<<ans[i]<<" ";
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

