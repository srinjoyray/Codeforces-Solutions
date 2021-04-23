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
    lli a[n],sum=0,pref[n+1]={0},suff[n+1]={0},temp,rem,ans=0;
    fo(i,n){
        cin>>a[i];
        sum+=a[i];
    }
    if(sum%3!=0){
        cout<<"0\n";
        return;
    }
    sum/=3;
    temp=0;
    fo2(i,1,n){
        temp+=a[i-1];
        pref[i]=pref[i-1];
        if(temp==sum){
            pref[i]++;
        }
    }
    temp=0;
    for(j=n-1,i=1;j>=0;j--,i++){
        temp+=a[j];
        suff[i]=suff[i-1];
        if(temp==sum){
            suff[i]++;
        }
    }
    /*fo2(i,1,n){
        cout<<pref[i]<<" ";
    }cout<<nl;
    fo2(i,1,n){
        cout<<suff[i]<<" ";
    }cout<<nl;*/
    fo2(i,1,n-2){
        if(pref[i]==pref[i-1]){
            continue;
        }
        rem=n-i;
        temp=suff[rem-1];
        ans+=temp;
    }
    cout<<ans<<nl;
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

