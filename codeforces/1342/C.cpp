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
lli pref[100000]={0};
lli calc(lli x,lli a,lli b){
    lli res=0,round;
    round=pref[a*b];
    res=(x/(a*b))*round;
    x%=(a*b);
    res+=pref[x];
    return res;
}
void solve(){
    lli i,j;
    lli a,b,q;
    lli l,r,ans,temp,mx,mn;
    cin>>a>>b>>q;
    mx=max(a,b);
    mn=min(a,b);
    pref[0]=0;
    fo2(i,1,a*b){
        pref[i]=pref[i-1];
        if(((i%a)%b) != ((i%b)%a)){
            pref[i]++;
        }
    }
    while(q--){
        cin>>l>>r;
        ans=calc(r,a,b)-calc(l-1,a,b);
        cout<<ans<<" ";
    }
    cout<<nl;

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

