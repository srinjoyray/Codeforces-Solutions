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
void solve(){
    int i,j;
    int n,k;
    cin>>n>>k;
    lli temp,ans=1,pos,l,r,count;
    vl a,b;
    
    map<lli,lli>present,position;
    fo(i,n){
        cin>>temp;
        a.pb(temp);
        position[temp]=i;
    }
    fo(i,k){
        cin>>temp;
        b.pb(temp);
        present[temp]++;
    }
    fo(i,k){
        temp=b[i];
        pos=position[temp];
        l=pos-1; r=pos+1;
        count=0;
        if(l>=0 && present[a[l]]==0){
            count++;
        }
        if(r<n && present[a[r]]==0){
            count++;
        }

        present[temp]--;
        ans*=count;
        ans%=mod;
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
    return 0;
}

