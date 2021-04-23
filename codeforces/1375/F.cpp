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
    lli a,b,c,y,input,h1,h2,d1,d2,h[3];
    cin>>a>>b>>c;
    cout<<"First\n";
    j=1;
    while(true){
        if(j==1){
            y=1e10;
        }
        if(j==2){
            h[0]=a;
            h[1]=b;
            h[2]=c;
            sort(h,h+3);
            h1=h[1]-h[0];
            h2=h[2]-h[1];
            y=h1+h2+h2;
        }
        if(j==3){
            d1=abs(a-b);
            d2=abs(a-c);
            y=min(d1,d2);
        }
        cout<<y<<endl;
        cin>>input;
        if(input==1){
            a+=y;
        }
        else if(input==2){
            b+=y;
        }
        else if(input==3){
            c+=y;
        }
        else{
            break;
        }
        j++;
        // deb2(a,b);
        // deb(c);
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

