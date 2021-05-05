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
    int n;
    cin>>n;
    int a,b,l,r,mat[n][n];
    pii white,black;
    white={1,1};
    black={1,2};
    fo(i,n*n){
        cin>>a;
        // a=i%3+1;
        if(a==1){
            if(black.F>n || black.F>n){   
                cout<<"3 ";
                cout<<white.F<<" "<<white.S<<endl;
                white.S+=2;
                if(white.S>n){
                    white.F++;
                    if(white.F%2==1){
                        white.S=1;
                    }
                    else{
                        white.S=2;
                    }
                }
            }
            else{
                cout<<"2 ";
                cout<<black.F<<" "<<black.S<<endl;
                black.S+=2;
                if(black.S>n){
                    black.F++;
                    if(black.F%2==1){
                        black.S=2;
                    }
                    else{
                        black.S=1;
                    }
                }
            }
        }
        else if(a==2){
            // deb2(white.F,white.S);
            if(white.F>n || white.S>n){
                cout<<"3 ";
                cout<<black.F<<" "<<black.S<<endl;
                black.S+=2;
                if(black.S>n){
                    black.F++;
                    if(black.F%2==1){
                        black.S=2;
                    }
                    else{
                        black.S=1;
                    }
                }
            }
            else{
                cout<<"1 ";
                cout<<white.F<<" "<<white.S<<endl;
                white.S+=2;
                if(white.S>n){
                    white.F++;
                    if(white.F%2==1){
                        white.S=1;
                    }
                    else{
                        white.S=2;
                    }
                }
            }
        }
        else if(a==3){
            
            if(white.F<=n && white.S<=n){
                cout<<"1 ";
                cout<<white.F<<" "<<white.S<<endl;
                white.S+=2;
                if(white.S>n){
                    white.F++;
                    if(white.F%2==1){
                        white.S=1;
                    }
                    else{
                        white.S=2;
                    }
                }
            }
            else if(black.F<=n && black.S<=n){
                cout<<"2 ";
                cout<<black.F<<" "<<black.S<<endl;
                black.S+=2;
                if(black.S>n){
                    black.F++;
                    if(black.F%2==1){
                        black.S=2;
                    }
                    else{
                        black.S=1;
                    }
                }
            }
        }

    }


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

