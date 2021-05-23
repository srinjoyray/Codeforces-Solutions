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
    // deb(n);
    lli x[n],y[n],u[n],v[n],l,r,count=0,temp;
    fo(i,n){
        cin>>x[i]>>y[i]>>u[i]>>v[i];
    }
    vpl v1;
    map<pl,lli> store;
    fo(i,n){
        l=u[i]-x[i];
        r=v[i]-y[i];
        temp=__gcd(abs(l),abs(r));
        l/=temp;
        r/=temp;
        if(l==0){
            r=r/abs(r);
        }
        else if(r==0){
            l=l/abs(l);
        }
        // deb2(l,r);
        v1.pb({l,r});
        store[{l,r}]++;
    }
    sort(all(v1));
    fo(i,n){
        l=v1[i].F;
        r=v1[i].S;
        temp=store[{-l,-r}];
        count+=temp;
    }

    cout<<count/2<<nl;
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

