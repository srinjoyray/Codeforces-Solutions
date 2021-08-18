#include<bits/stdc++.h>
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define fo2(i,start,end) for(i=start;i<=end;i++)
#define rfo(i,n) for(i=n-1;i>=0;i--)
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
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
const int N=1e6+10;
vector<string> v;
int check(string a,string b){
    int i=0,j=0;
    while(i<a.size()){
        while(j<b.size() && a[i]!=b[j]){
            j++;
        }
        if(j==b.size()){
            break;
        }
        i++;
        j++;
    }
    int common,total;
    common=i;
    total=b.size()-common+(a.size()-common);
    // deb2(a,b);
    // deb(total);
    return total;
}
void solve(){
    int i,j;
    string s;
    cin>>s;
    int ans=50,temp;
    fo(i,v.size()){
        temp=check(v[i],s);
        if(temp==3){
            // deb(v[i]);
        }
        ans=min(ans,temp);
    }
    cout<<ans<<nl;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t=1;
    cin>>t;
    string temp;
    for(ll i=1;i<=1e18;i*=2){
        temp=to_string(i);
        v.pb(temp);
    }
    while(t--){
        solve();
    }
    
}

