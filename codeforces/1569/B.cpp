#include<bits/stdc++.h>
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define fo2(i,start,end) for(i=start;i<=end;i++)
#define rfo(i,n) for(i=n-1;i>=0;i--)
#define ll long long int
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
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
const int N=1e6+10;

void solve(){
    int i,j;
    int n;
    cin>>n;
    string s;
    char a[n][n];
    memset(a,'#',sizeof a);
    cin>>s;
    fo(i,n){
        fo(j,n){
            if(i==j){
                a[i][j]='X';
            }
        }
    }

    fo(i,n){
        if(s[i]=='1'){
            fo(j,n){
                if(i==j){
                    continue;
                }
                a[i][j]='=';
                a[j][i]='=';
            }
        }
    }

    // fo(i,n){
    //     fo(j,n){
    //         cout<<a[i][j];
    //     }
    //     cout<<nl;
    // }
    bool flag;
    fo(i,n){
        if(s[i]=='2'){
            flag=false;
            fo(j,n){
                if(a[i][j]=='+'){
                    flag=true;
                }
                if(a[i][j]!='#'){
                    continue;
                }
                if(!flag){
                    a[i][j]='+';
                    a[j][i]='-';
                    flag=true;
                }  
                else{
                    a[i][j]='-';
                    a[j][i]='+';
                }
            }
            if(!flag){
                cout<<"NO\n";
                return;
            }
        }
    }

    cout<<"YES\n";
    fo(i,n){
        fo(j,n){
            cout<<a[i][j];
        }
        cout<<nl;
    }
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    
}

