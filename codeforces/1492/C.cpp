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
    int n,m;
    cin>>n>>m;
    string s,t;
    cin>>s>>t;
    int left[m],right[m],mx=1,temp;
    for(i=0,j=0;i<n && j<m; i++){
        if(s[i]==t[j]){
            left[j]=i;
            j++;
        }
    }
    for(i=n-1,j=m-1;i>=0 && j>=0;i--){
        if(s[i]==t[j]){
            right[j]=i;
            // deb2(j,right[j]);
            j--;
        }
    }
    fo(i,m){
        // cout<<left[i]<<" "<<right[i]<<endl;
    }
    fo(i,m-1){
        temp=right[i+1]-left[i];
        mx=max(mx,temp);
    }
    cout<<mx<<endl;
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

