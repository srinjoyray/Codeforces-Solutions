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
const int N=1e6+10;
void solve(){
    int i,j;
    int n,m;
    cin>>n>>m;
    ll l[m+1],sum=0,mn;
    bool flag=false;
    fo2(i,1,m){
        cin>>l[i];
        if(l[i]+i-1>n){
            flag=true;
        }
        sum+=l[i];
    }
    if(sum<n || flag){
        cout<<"-1\n";
        return;
    }
    ll p[m+1],suff[m+2]={0},temp;
    for(i=m;i>=1;i--){
        suff[i]=suff[i+1]+l[i];
    }
    fo2(i,1,m){
        temp=max((ll)i,n-suff[i]+1);
        p[i]=temp;
    }
    fo2(i,1,m){
        cout<<p[i]<<" ";
    }cout<<nl;

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
    
}

