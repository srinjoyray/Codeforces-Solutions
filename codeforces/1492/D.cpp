#include<bits/stdc++.h>
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define fo2(i,start,end) for(i=start;i<=end;i++)
#define rfo(i,n) for(i=n-1;i>=0;i--)
#define lli long long int
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
typedef pair<lli, lli>	pl;
typedef vector<int>		vi;
typedef vector<lli>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
void solve(){
    int i,j;
    int a,b,k,mx;
    cin>>a>>b>>k;
    string s1,s2;

    if(k==0){
        cout<<"Yes\n";
        fo(i,b){
            s1.pb('1');
            s2.pb('1');
        }
        fo(i,a){
            s1.pb('0');
            s2.pb('0');
        }
        cout<<s1<<nl<<s2<<nl;
        return;
    }

    s1.pb('1'); s2.pb('1');
    b--;
    if(a==0 || b==0 || k>a+b-1){
        cout<<"No\n";
        return;
    }
    s1.pb('1'); s2.pb('0');
    while(k>1){
        if(a>1){
            s1.pb('0');
            s2.pb('0');
            a--;
        }
        else if(b>1){
            s1.pb('1');
            s2.pb('1');
            b--;
        }
        k--;
    }
    s1.pb('0');
    s2.pb('1');
    a--;
    b--;
    while(a--){
        s1.pb('0');
        s2.pb('0');
    }
    while(b--){
        s1.pb('1');
        s2.pb('1');
    }
    cout<<"Yes\n";
    cout<<s1<<nl<<s2<<nl;
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

