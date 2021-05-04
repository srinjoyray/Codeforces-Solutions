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
    lli a[n+1],b[n+1],store[n+1]={0},sum=0,temp,mn=0;
    fo2(i,1,n){
        cin>>a[i]>>b[i];
        mn+=a[i];
    }
    store[1]=max(a[1]-b[n],store[1]);
    fo2(i,2,n){
        store[i]=max(a[i]-b[i-1],store[i]);
    }
    fo2(i,1,n){
        sum+=store[i];
        // deb2(i,store[i]);
    }
    fo2(i,1,n){
        temp=(sum-store[i])+a[i];
        mn=min(mn,temp);
    }
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

