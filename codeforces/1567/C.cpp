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
ll find(ll dig){

    ll mn,mx,ans;
    mx=min((ll)9,dig);
    mn=max((ll)0,dig-9);
    ans=mx-mn+1;
    deb2(dig,ans);
    return ans;
}

void solve(){
    int i,j;
    string s,a,b;
    cin>>s; 
    ll n,sz,num1,num2,ans;
    sz=s.size();

    fo(i,sz){
        if(i%2==0){
            a.pb(s[i]);
        }
        else{
            b.pb(s[i]);
        }
    }
    num1=stoll(a);
    if(b.size()>0){
        num2=stoll(b);
    }
    else{
        num2=0;
    }
    
    ans=(num1+1)*(num2+1);
    cout<<ans-2<<nl;
    
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
    
}

