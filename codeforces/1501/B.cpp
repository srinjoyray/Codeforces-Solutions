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
    int a[n+1],pref[n+1]={0},sum=0,temp;
    fo2(i,1,n){
        cin>>a[i];
    }
    fo2(i,1,n){
        if(a[i]==0){
            continue;
        }
        temp=max(1,i-a[i]+1);
        pref[temp]--;
        pref[i]++;
    }
    /*fo2(i,1,n){
        // cout<<pref[i]<<" ";
    }
    cout<<endl;*/
    fo2(i,1,n){
        sum+=pref[i];
        if(sum==0 && a[i]==0){
            cout<<"0 ";
        }
        else{
            cout<<"1 ";
        }
        
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

