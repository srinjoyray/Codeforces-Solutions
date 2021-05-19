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
    int n,k;
    cin>>n>>k;
    int a[n],temp,ans,l,r;
    fo(i,n){
        cin>>a[i];
    }
    vi v,vmin,vmax;
    fo(i,n/2){
        v.pb(a[i]+a[n-1-i]);
        temp=min(a[i],a[n-1-i]);
        vmin.pb(temp+1);
        temp=max(a[i],a[n-1-i]);
        vmax.pb(temp+k);
    }
    map<lli,lli> freq;

    fo(i,v.size()){
        freq[v[i]]++;
    }
    l=*max_element(all(vmin));
    r=*min_element(all(vmax));
    // deb2(l,r);
    /*fo(i,v.size()){
        cout<<v[i]<<"@";
    }cout<<nl;*/
    ans=n;
    
    sort(all(vmin));
    sort(all(vmax));
    int arr[2*k+1]={0},pref[2*k+1]={0};
    fo(i,n/2){
        arr[vmin[i]]++;
        arr[vmax[i]+1]--;
    }
    fo2(i,1,2*k){
        pref[i]=pref[i-1]+arr[i];
    }

    fo2(i,1,2*k){
        temp=pref[i]-freq[i]+2*(n/2-pref[i]);
        // deb2(i,temp);
        ans=min(temp,ans);
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
    return 0;
}

