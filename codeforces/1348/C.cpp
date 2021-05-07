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
    int i,j,p;
    int n,k;
    cin>>n>>k;
    // deb2(n,k);
    string s,ans;
    cin>>s;
    sort(all(s));
    // deb(s);
    if(s[k-1]!=s[0]){
        cout<<s[k-1]<<nl;
        return;
    }
    int num,rem,temp;
    ans.pb(s[0]);
    fo2(i,k,n-1){
        j=i+1;
        while(j<n && s[i]==s[j]){
            j++;
        }
        temp=j-i;
        if(j==n){
            num=(temp+k-1)/k;
            fo(p,num){
                ans.pb(s[i]);
            }
            break;
        }
        for(;i<n;i++){
            ans.pb(s[i]);
        }

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


