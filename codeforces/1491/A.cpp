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
    int n,q;
    cin>>n>>q;
    int a[n],one=0,zero=0;
    fo(i,n){
        cin>>a[i];
        if(a[i]==0){
            zero++;
        }
        else if(a[i]==1){
            one++;
        }
    }
    while(q--){
        int t;
        cin>>t;
        if(t==1){
            int x;
            cin>>x;
            if(a[x-1]==1){
                one--;
                zero++;
            }
            else{
                one++;
                zero--;
            }
            a[x-1]=1-a[x-1];

        }
        else if(t==2){
            int k;
            cin>>k;
            if(one>=k){
                cout<<"1\n";
            }
            else{
                cout<<"0\n";
            }
        }

    }
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
