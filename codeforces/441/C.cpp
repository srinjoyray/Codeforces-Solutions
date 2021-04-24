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
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define tr(it,a) for(auto it=a.begin(); it!=a.end();it++)
#define nl '\n'
#define PI 3.1415926535897932384626
#define mod 1000000007
typedef pair<int, int>	pii;
typedef pair<lli, lli>	pl;
typedef vector<int>		vi;
typedef vector<lli>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
void solve(){
    int i,j,q;
    int n,m,k,dir;
    cin>>n>>m>>k;
    // deb2(n,m);
    i=1;j=1;
    dir=1;
    fo(q,k-1){
        cout<<"2 ";
        cout<<i<<" "<<j<<" ";
        if(j==m && dir==1){
            i++;
            dir*=-1;
        }
        else if(j==1 && dir==-1){
            i++;
            dir*=-1;
        }
        else{
            if(dir==1){
                j++;
            }
            else{
                j--;
            }
        }
        cout<<i<<" "<<j<<" ";
        if(j==m && dir==1){
            i++;
            dir*=-1;
        }
        else if(j==1 && dir==-1){
            i++;
            dir*=-1;
        }
        else{
            if(dir==1){
                j++;
            }
            else{
                j--;
            }
        }
        cout<<nl;
    }
    cout<<(n*m)-2*(k-1)<<" ";
    while(i<=n){
        // deb2(i,j);
        // deb(dir);
        if(dir==1){
            while(j<=m){
                cout<<i<<" "<<j<<" ";
                j++;
            }
            j=m;
            dir*=-1;
            i++;
        }
        else if(dir==-1){
            while(j>=1){
                cout<<i<<" "<<j<<" ";
                j--;
            }
            j=1;
            dir*=-1;
            i++;
        }
    }

        /*fo2(i,1,k-1){
            cout<<m<<" ";
            fo2(j,1,m){
                cout<<i<<" "<<j<<" ";
            }
            cout<<nl;
        }
        dir=1;
        cout<<(n-i+1)*m<<" ";
        // deb(i);
        while(i<=n){
            if(dir==1){
                fo2(j,1,m){
                    cout<<i<<" "<<j<<" ";
                }
                dir=-1;
            }
            else if(dir==-1){
                for(j=m;j>=1;j--){
                    cout<<i<<" "<<j<<" ";
                }
                dir=1;
            }
            i++;
        }
        cout<<nl;
    */
    
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

