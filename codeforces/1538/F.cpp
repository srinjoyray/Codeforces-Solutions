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
ll digitdp(ll num){
    ll digit=0,temp,curr=0,ans=0;
    /*temp=num;
    while(temp){
        digit++;
        temp/=10;
    }*/

    string s=to_string(num);
    int i,dig;
    fo(i,s.size()){
        dig=s[i]-'0';
        ans+=curr*10+dig;

        curr=(curr*10)+dig;
        // deb2(curr,dig);
    }
    return ans;

}
void solve(){
    int i,j;
    ll l,r,ans;
    cin>>l>>r;
    ans=digitdp(r);
    // deb(ans);
    ans-=digitdp(l);
    // deb(ans);
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
}

