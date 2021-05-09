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
bool comp(pl a, pl b){
    if(a.F==0){
        b.F>a.F;
    }
    return a.F<b.F;
}
void solve(){
    int i,j;
    int n;
    cin>>n;
    lli a[n],b[n],suff[n+1],temp,mn;
    fo(i,n){
        cin>>a[i];
    }
    fo(i,n){
        cin>>b[i];
    }
    vpl v;
    fo(i,n){
        v.pb({a[i],b[i]});
    }
    sort(all(v),comp);
    fo(i,n){
        // deb2(v[i].F,v[i].S);
    }
    
    suff[n]=v[n-1].S;
    for(i=n-2;i>=0;i--){
        suff[i+1]=suff[i+2]+v[i].S;
    }
    fo2(i,1,n){
        // deb2(i,suff[i]);
    }
    mn=v[n-1].F;
    fo2(i,1,n-1){
        temp=max(v[i-1].F,suff[i+1]);
        // deb2(i,temp);
        mn=min(mn,temp);
    }
    mn=min(mn,suff[1]);
    mn=min(mn,*max_element(a,a+n));
    cout<<mn<<nl;
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

