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
    int n,t,k,l,r,mid,input;
    cin>>n>>t;
    l=1; r=n;
    int zero,ans;
    while(t--){
        cin>>k;

        while(l<=r){
            // deb2(l,r);
            mid=(l+r)/2;
            cout<<"? "<<l<<" "<<mid<<endl;
            cin>>input;
            if(l==r){
                cout<<"! "<<l<<endl;
                break;
            }
            if(r==l+1){
                if(input==0 && k==1){
                    ans=l;
                }
                else{
                    ans=r;
                }
                cout<<"! "<<ans<<endl;
                break;
            }
            zero=(mid-l+1)-input;
            // deb2(k,zero);
            if(k<=zero){
                r=mid;
            }
            else if(k>zero){
                k-=zero;
                l=mid+1;
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

