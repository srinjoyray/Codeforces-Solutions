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
#define mod 998244353
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
const int N=1e6;
ll fact[N];
ll power(ll a,ll n){
    ll res=1;
    while(n){
        if(n%2){
            res=(res*a)%mod;
        }
        n/=2;
        a=(a*a)%mod;
    }
    return res;
}
ll ncr(ll n,ll r){
    // deb2(n,r);
    if(r>n){
        return 0;
    }
    ll ans,num,denom;
    num=fact[n];
    denom=(fact[r]*fact[n-r])%mod;
    denom=power(denom,mod-2);
    ans=(num*denom)%mod;
    return ans;
}
void solve(){
    int i,j;
    int n,k;
    cin>>n>>k;
    ll l[n],r[n];
    vpl v;
    fo(i,n){
        cin>>l[i]>>r[i];
        v.pb({l[i],r[i]});
    }
    sort(all(v));
    fo(i,n){
        // cout<<v[i].F<<" "<<v[i].S<<nl;
    }
    multiset<ll> se;
    ll ans=0,count,temp;
    fo(i,n){
        if(se.size()>0){
            while(*(se.begin())<v[i].F){
                se.erase(se.begin());
            }
        }
        temp=se.size();
        // deb(temp);
        count=ncr(temp,k-1);
        ans+=count;
        ans%=mod;
        se.insert(v[i].S);
        /*for(auto itr=se.begin();itr!=se.end();itr++){
            cout<<(*itr)<<" ";
        }cout<<nl;*/
    }
    cout<<ans<<nl;
}


int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t=1;
    // cin>>t;
    fact[0]=1; fact[1]=1;
    for(int i=2;i<N;i++){
        fact[i]=(fact[i-1]*i)%mod;
    }
    while(t--){
        solve();
    }
}

