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
    ll x,y,a,b,gap1,gap2,sum;
    cin>>x>>y>>a>>b;
    if(x>y){
        swap(x,y);
    }
    if(a>b){
        swap(a,b);
    }

    gap1=y-x;
    gap2=b-a;
    sum=a+b;
    ll upto=0,ans=0;
    if(gap2==0){
        ans=x/a;
        cout<<ans<<nl;
        return;
    }
    if(gap1>gap2){
        upto=gap1/gap2;
    }
    upto=min(upto,x/a);
    upto=min(upto,y/b);

    ans+=upto;
    x-=upto*a;
    y-=upto*b;

    // deb2(x,y);
    // deb(ans);

    upto=x/sum;
    ans+=upto*2;
    x-=upto*sum;
    y-=upto*sum;

    // deb2(x,y);
    // deb(ans);
  
    if(x>=a && y>=b){
        ans++;
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

