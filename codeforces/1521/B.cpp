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
    lli a[n],temp,mn,pos;
    vl ans;
    fo(i,n){
        cin>>a[i];
    }
    mn=*min_element(a,a+n);
    fo(i,n){
        if(a[i]==mn){
            pos=i;
            break;
        }
    }
    if(pos!=0){
        ans.pb(1);
        ans.pb(pos+1);
        ans.pb(mn);
        ans.pb(mn);
    }
    for(i=1;i<n;i++){
        if(i%2==1){
            temp=mn+1;
        }
        else{
            temp=mn;
        }
        ans.pb(i+1);
        ans.pb(1);
        ans.pb(temp);
        ans.pb(mn);
    }
    cout<<ans.size()/4<<nl;
    fo(i,ans.size()){
        cout<<ans[i]<<" ";
        if((i+1)%4==0){
            cout<<nl;
        }
    }
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

