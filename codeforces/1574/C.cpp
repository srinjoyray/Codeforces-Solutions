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

void solve(){
    int i,j;
    int n;
    cin>>n;
    ll a[n],sum=0;
    set<ll> se;
    fo(i,n){
        cin>>a[i];
        sum+=a[i];
        se.insert(a[i]);
    }
    int m;
    cin>>m;
    ll x[m],y[m],val,ans,temp,rem;
    fo(i,m){
        cin>>x[i]>>y[i];
    }


    fo(i,m){
        ans=INT64_MAX;
        // deb2(x[i],y[i]);
        if(*se.begin()<x[i]){
            val=*(--se.lower_bound(x[i]));
            // deb(val);
            temp=x[i]-val;
            rem=sum-val;
            if(rem<y[i]){
                temp+=y[i]-rem;
            }
            ans=min(ans,temp);
        }

        if(se.lower_bound(x[i])!=se.end()){
            val=*se.lower_bound(x[i]);
            // deb(val);
            rem=sum-val;
            temp=0;
            if(rem<=y[i]){
                temp+=y[i]-rem;
            }
            ans=min(ans,temp);
        }


        cout<<ans<<nl;
    }
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

