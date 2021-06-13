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
const ll inf =1e15;
void solve(){
    int i,j;
    ll x,y;
    cin>>x>>y;
    ll c[7],right,top,diag,ans=0,temp;
    fo2(i,1,6){
        cin>>c[i];
    }

    if(x>=0 && y>=0){
        right=min(c[6],c[5]+c[1]);
        top=min(c[2],c[1]+c[3]);
        diag=min(c[1],c[2]+c[6]);
    }
    else if(x<0 && y<0){
        right=min(c[3],c[2]+c[4]);
        top=min(c[5],c[4]+c[6]);
        diag=min(c[4],c[5]+c[3]);
    }
    else if(x>=0 && y<0){
        right=min(c[6],c[5]+c[1]);
        top=min(c[5],c[4]+c[6]);
        diag=inf;
    }
    else if(x<0 && y>=0){
        right=min(c[3],c[2]+c[4]);
        top=min(c[2],c[1]+c[3]);
        diag=inf;
    }

    x=abs(x);
    y=abs(y);

    if(diag>=right+top){
        ans=x*right+y*top;
    }
    else{
        temp=min(x,y);
        ans=temp*diag + right*(x-temp) + top*(y-temp);
    }
    cout<<ans<<nl;
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

