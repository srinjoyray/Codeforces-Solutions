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
void solve(){
    int i,j;
    int n,m;
    cin>>n>>m;
    string s[n];
    fo(i,n){
        cin>>s[i];
    }
    int r=-1,w=-1;
    fo(i,n){
        fo(j,m){
            if(s[i][j]=='W'){
                if(w==-1){
                    w=(i+j)%2;
                    r=1-w;
                }
                else if(w!=(i+j)%2){
                    cout<<"NO\n";
                    return;
                }
            }
            if(s[i][j]=='R'){
                if(r==-1){
                    r=(i+j)%2;
                    w=1-r;
                }
                else if(r!=(i+j)%2){
                    cout<<"NO\n";
                    return;
                }
            }
        }
    }

    if(r==-1){
        r=0;
        w=1;
    }

    fo(i,n){
        fo(j,m){
            if(r==(i+j)%2){
                s[i][j]='R';
            }
            else{
                s[i][j]='W';
            }
        }
    }
    cout<<"YES\n";
    fo(i,n){
        cout<<s[i]<<nl;
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

