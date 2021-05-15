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
    string s,a,b,ans;
    cin>>s;
    fo(i,s.size()){
        if((s[i]-'0')%2==0){
            a.pb(s[i]);
        }
        else{
            b.pb(s[i]);
        }
    }   
    // deb2(a,b); 
    i=0; j=0;
    while(i<a.size() && j<b.size()){
        if(a[i]<b[j]){
            ans.pb(a[i]);
            i++;
        }
        else{
            ans.pb(b[j]);
            j++;
        }
    }
    while(i<a.size()){
        ans.pb(a[i]);
        i++;
    }
    while(j<b.size()){
        ans.pb(b[j]);
        j++;
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

