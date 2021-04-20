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
    int i,j;
    int n,games,win,loss;
    cin>>n;
    int w[n+1]={0},l[n+1]={0};
    if(n%2==1){
        games=n-1;
        win=games/2;
        fo2(i,1,n){
            loss=games/2-l[i];
            fo2(j,i+1,n){
                if(w[j]<win && loss>0){
                    w[j]++;
                    loss--;
                    l[i]++;
                    cout<<"-1 ";
                }
                else{
                    w[i]++;
                    l[j]++;
                    cout<<"1 ";
                }
            }
        }
        cout<<nl;
        return;
    }
    else{
        games=n-1;
        win=games/2;
        fo2(i,1,n){
            loss=games/2-l[i];
            fo2(j,i+1,n){
                if(j==i+1 && i%2==1){
                    cout<<"0 ";
                    continue;
                }
                if(w[j]<win && loss>0){
                    w[j]++;
                    loss--;
                    l[i]++;
                    cout<<"-1 ";
                }
                else{
                    w[i]++;
                    l[j]++;
                    cout<<"1 ";
                }
            }
        }
        cout<<nl;
        return;

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
    return 0;
}

