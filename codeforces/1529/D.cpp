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
#define mod 998244353
typedef pair<int, int>	pii;
typedef pair<lli, lli>	pl;
typedef vector<int>		vi;
typedef vector<lli>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
lli fact[1000001]={0};
void solve(){
    int i,j;
    lli n,sum=1,pref=1,val;
    cin>>n;
    // deb(n);
    if(n==1){
        cout<<sum<<nl;
        return;
    }
    
    for(int i=1;i<1000001;i++){
        for(j=i;j<1000001;j+=i){
            fact[j]++;
        }
        fact[i]%=mod;
    }
    
    for(i=2;i<=n;i++){
        val=fact[i];
        sum=pref+val;
        pref+=sum;
        pref%=mod;
        // deb2(i,sum);
    }
    sum%=mod;
    cout<<sum<<nl;

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

