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

bool check(ll val,ll n,ll s,vpl v){
    // deb2(val,s);
    // return true;
    ll i,req,temp,count=0;
    req=(n+1)/2;
    fo(i,n){
        s-=v[i].F;
        if(v[i].F>=val){
            count++;
        }
    }
    
    if(count>=req){
        return true;
    }
    vl curr;
    fo(i,n){
        if(v[i].F<val && v[i].S>=val){
            curr.pb(val-v[i].F);
        }
    }
    sort(all(curr));
    // fo(i,curr.size()){
    //     cout<<curr[i]<<nl;
    // }
    // deb(s);
    fo(i,curr.size()){
        if(curr[i]<=s){
            
            s-=curr[i];
            count++;
        }
        else{
            break;
        }
    }
    
    if(count>=req){
        return true;
    }
    else{
        return false;
    }
}
void solve(){
    int i,j;
    ll n,s;
    cin>>n>>s;
    vpl v;
    fo(i,n){
        ll l,r;
        // l=1000000000;
        // r=1000000000;
        cin>>l>>r;
        // deb2(l,r);
        v.pb({l,r});
    }
   

    ll left,right,mid,ans=0;
    left=0;
    right=1e9+10;
    int k=5;
    while(left<=right ){
        // deb2(left,right);
        mid=(left+right)/2;
        if(check(mid,n,s,v)){
            ans=mid;
            left=mid+1;
        }
        else{
            right=mid-1;
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
}

