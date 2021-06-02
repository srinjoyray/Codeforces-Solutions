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
ll func(ll a[],set<ll> s1,set<ll> s2,int n){
    int i;
    ll ans=INT64_MAX,l,r,temp;
    fo(i,n){
        if(*s1.begin()>a[i]){
            continue;
        }
        if(s2.lower_bound(a[i])==s2.end()){
            continue;
        }
        l=*(--s1.upper_bound(a[i]));
        r=*(s2.lower_bound(a[i]));
        temp=(a[i]-l)*(a[i]-l)+ (a[i]-r)*(a[i]-r) +(l-r)*(l-r);
        ans=min(ans,temp); 
    }
    return ans;
}
void solve(){
    int i,j,k;
    int nr,ng,nb;
    cin>>nr>>ng>>nb;
    ll r[nr],g[ng],b[nb],temp,ans=INT64_MAX;
    set<ll> s1,s2,s3;
    fo(i,nr){
        cin>>r[i];
    }
    fo(i,ng){
        cin>>g[i];
    }
    fo(i,nb){
        cin>>b[i];
    }
    fo(i,nr){
        s1.insert(r[i]);
    }
    fo(i,ng){
        s2.insert(g[i]);
    }
    fo(i,nb){
        s3.insert(b[i]);
    }
    temp=func(g,s1,s3,ng);
    ans=min(ans,temp);
    temp=func(g,s3,s1,ng);
    ans=min(ans,temp);
    temp=func(r,s2,s3,nr);
    ans=min(ans,temp);
    temp=func(r,s3,s2,nr);
    ans=min(ans,temp);
    temp=func(b,s1,s2,nb);
    ans=min(ans,temp);
    temp=func(b,s2,s1,nb);
    ans=min(ans,temp);
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

