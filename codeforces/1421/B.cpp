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
    int n,count=0;
    cin>>n;
    string s[n],a[n],b[n];
    fo(i,n){
        cin>>s[i];
        a[i]=s[i];
        b[i]=s[i];
    }
    a[0][1]='1'; a[1][0]='1'; a[n-1][n-2]='0'; a[n-2][n-1]='0';
    b[0][1]='0'; b[1][0]='0'; b[n-1][n-2]='1'; b[n-2][n-1]='1';
    count=0;
    fo(i,n){
        fo(j,n){
            if(a[i][j]!=s[i][j]){
                count++;
            }
        }
    }
    // deb(count);
    if(count<=2){
        cout<<count<<nl;
        fo(i,n){
            fo(j,n){
                if(a[i][j]!=s[i][j]){
                   cout<<i+1<<" "<<j+1<<nl;
                }
            }
        }
        return;
    }
    count=0;
    fo(i,n){
        fo(j,n){
            if(b[i][j]!=s[i][j]){
                count++;
            }
        }
    }
    // deb(count);
    if(count<=2){
        cout<<count<<nl;
        fo(i,n){
            fo(j,n){
                if(b[i][j]!=s[i][j]){
                   cout<<i+1<<" "<<j+1<<nl;
                }
            }
        }
        return;
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

