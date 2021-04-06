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
    lli k,dist;
    cin>>n>>k;
    int x[n],y[n];
    bool flag=false;
    fo(i,n){
        cin>>x[i]>>y[i];
    }
    fo(i,n){
        flag=true;
        fo(j,n){
            if(i==j){
                continue;
            }
            dist=abs(x[i]-x[j])+abs(y[i]-y[j]);
            if(dist>k){
                flag=false;
                break;
            }
        }
        if(flag==true){
            break;
        }
    }
    if(flag){
        cout<<1<<nl;
    }
    else{
        cout<<"-1\n";
    }
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

