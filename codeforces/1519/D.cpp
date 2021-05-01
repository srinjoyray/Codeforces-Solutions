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
    int i,j,k;
    int n;
    cin>>n;
    lli a[n],b[n],sum=0,mx,temp;
    fo(i,n){
        cin>>a[i];
    }
    fo(i,n){
        cin>>b[i];
    }
    fo(i,n){
        sum+=a[i]*b[i];
    }
    mx=sum;
    // Odd Length Subarray
    for(k=1;k<n-1;k++){
        i=k-1;
        j=k+1;
        temp=sum;
        while(i>=0 && j<n){
            temp-=(a[i]*b[i] + a[j]*b[j]);
            temp+=(a[i]*b[j] + b[i]*a[j]);
            mx=max(temp,mx);
            i--;j++;
        }
    }
    // Even length subarray
    for(k=0;k<n-1;k++){
        i=k;
        j=k+1;
        temp=sum;
        while(i>=0 && j<n){
            temp-=(a[i]*b[i] + a[j]*b[j]);
            temp+=(a[i]*b[j] + b[i]*a[j]);
            mx=max(temp,mx);
            i--;j++;
        }
    }
    cout<<mx<<nl;

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

