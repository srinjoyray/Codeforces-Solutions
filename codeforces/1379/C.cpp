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
const ll inf=1e15;
void solve(){
    int i,j;
    ll n,m;
    cin>>m>>n;
    ll a[n],b[n];
    vpl v(n);
    fo(i,n){
        cin>>a[i]>>b[i];
        v[i]={a[i],b[i]};
    }
    set<ll> se;
    map<ll,pl> mapp;
    sort(a,a+n,greater<ll>());
    ll count=0,sum=0;
    fo(i,n){
        j=i;
        while(j<n && a[j]==a[i]){
            sum+=a[j];
            j++;
            count++;
        }
        // deb(a[i]);
        // deb2(count,sum);
        se.insert(a[i]);
        mapp[a[i]]={count,sum};
        i=j-1;
    }
    ll other,ans=0,temp,val,rem;
    fo(i,n){
        if(se.upper_bound(b[i])==se.end()){
            other=0;
            sum=0;
        }
        else{
            val=*se.upper_bound(b[i]);
            // deb(val);
            sum=mapp[val].S;
            other=mapp[val].F;
        }
        if(v[i].F<=b[i]){
            other++;
            sum+=v[i].F;
        }
        // deb2(sum,other);
        rem=m-other;
        if(rem<0){
            continue;
        }
        temp=sum+rem*b[i];
        // deb(temp);
        ans=max(ans,temp);
    }
    // deb(ans);
    if(m<=n){
        temp=0;
        fo(i,m){
            temp+=a[i];
        }
        ans=max(ans,temp);
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

