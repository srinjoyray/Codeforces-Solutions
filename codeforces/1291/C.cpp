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
    int n,m,k;
    cin>>n>>m>>k;
    lli a[n],temp1,temp2,temp,mx=0,temp_mx,rem,last,tot;
    fo(i,n){
        cin>>a[i];
    }
    if(k>=m-1){
        temp=0;
        j=n-1;
        fo(i,m){
            temp=max(temp,a[i]);
            temp=max(temp,a[j]);
            j--;
        }
        cout<<temp<<nl;
        return;
    }
    rem=m-k-1;
    last=n-m;
    for(i=0;i<=k;i++){
        temp=INT64_MAX;
        for(j=0;j<=rem;j++){
            // tot=i+j;
            temp_mx=max(a[i+j],a[i+j+last]);
            temp=min(temp,temp_mx);
        }    
        mx=max(mx,temp);
    }
    cout<<mx<<nl;
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

