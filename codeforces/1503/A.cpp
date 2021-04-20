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
    string s,a,b;
    cin>>s;
    int count=0,last,temp;
    fo(i,n){
        if(s[i]=='1'){
            count++;
        }
    }
    if(s[0]=='0' || s[n-1]=='0' || count%2==1){
        cout<<"NO\n";
        return ;
    }
    temp=0;
    last=0;
    fo(i,n){
        if(s[i]=='1'){
            if(temp<count/2){
                a.pb('(');
                b.pb('(');
                temp++;
            }
            else{
                a.pb(')');
                b.pb(')');
            }
        }
        else{
            if(last==0){
                a.pb('(');
                b.pb(')');
                last=1;
            }
            else{
                a.pb(')');
                b.pb('(');
                last=0;
            }
        }
    }
    cout<<"YES\n";
    cout<<a<<nl<<b<<nl;
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

