#include<bits/stdc++.h>
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define fo2(i,start,end) for(i=start;i<=end;i++)
#define rfo(i,n) for(i=n-1;i>=0;i--)
#define lli long long int
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
typedef pair<lli, lli>	pl;
typedef vector<int>		vi;
typedef vector<lli>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
void solve(){
    int i,j;
    int n;
    cin>>n;
    ll a[n],count;
    fo(i,n){
        // a[i]=i+1;
        cin>>a[i];

    }
    vl v;
    for(i=n-2;i>=0;i--){
        v.pb(1);    v.pb(i+1);  v.pb(i+2);
        a[i]+=a[i+1];
    }
    // deb(v.size()/3);
    /*fo(i,n){
        cout<<a[i]<<" ";
    }cout<<nl;*/
    for(i=n-1;i>0;i--){
        v.pb(2);    v.pb(i);   v.pb(i+1);
        a[i]=a[i]-a[i-1];
    }
    // deb(v.size()/3);
    /*fo(i,n){
        cout<<a[i]<<" ";
    }cout<<nl;*/
    fo(i,n-1){
        v.pb(2);    v.pb(i+1);  v.pb(i+2);
        a[i+1]=a[i+1]-a[i];
        v.pb(1);    v.pb(i+1);  v.pb(i+2);
        a[i]=a[i]+a[i+1];
    }
    // deb(v.size()/3);
    /*fo(i,n){
        cout<<a[i]<<" ";
    }cout<<nl;*/
    for(count=1,i=n-2;i>=0;i--,count++){
        if(count%2==1){
            v.pb(2);    v.pb(i+1);  v.pb(n);
            v.pb(2);    v.pb(i+1);  v.pb(n);
            a[n-1]-=2*a[i]; 
        }
        else{
            continue;
        }
        // deb2(a[n-1],a[i]);
    }
    // deb(v.size()/3);
    /*fo(i,n){
        cout<<a[i]<<" ";
    }cout<<nl;*/
    
    /*fo(i,n-1){
        v.pb(2);v.pb(i+1); v.pb(n);
        a[n-1]=a[n-1]-a[i];
    }*/
    
    
    /*fo(i,n){
        cout<<a[i]<<" ";
    }cout<<nl;*/
    // deb(v.size()/3);
    cout<<v.size()/3<<nl;
    for(i=0;i<v.size();i+=3){
        cout<<v[i]<<" "<<v[i+1]<<" "<<v[i+2]<<nl;
        
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

