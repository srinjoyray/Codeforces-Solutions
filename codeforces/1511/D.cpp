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
    lli n,k,len,num,rem;
    cin>>n>>k;
    // deb2(n,k);
    char ch;
    string s;
    for(i=0;i<k;i++){
        ch='a'+i;
        s.pb(ch);
        for(j=i+1;j<k;j++){
            s.pb(ch);
            s.pb('a'+j);
        }
    }
    // deb(s);
    len=s.size();
    num=n/len;
    rem=n%len;
    fo(i,num){
        cout<<s;
    }
    fo(i,rem){
        cout<<s[i];
    }
    cout<<nl;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

