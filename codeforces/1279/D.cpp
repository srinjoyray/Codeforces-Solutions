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
const int N=1e6+10;
ll power(ll a,ll n){
    ll res=1;
    while(n){
        if(n%2){
            res=(res*a)%mod;
        }
        a=(a*a)%mod;
        n/=2;
    }
    return res;
}
void solve(){
    int i,j;
    ll n,sum=0,ans=0;
    cin>>n;
    map<int,int> mapp;
    vl v[n];
    fo(i,n){
        int k,inp;
        cin>>k;
        sum+=k;
        fo(j,k){
            cin>>inp;
            v[i].pb(inp);
            mapp[inp]++;
        }

    }
    ll denom,term,temp,res;
    denom=power(n,mod-2);
    term=denom;
    fo(i,n){
        int k = v[i].size();
        denom=power(k,mod-2);
        temp=(term*denom)%mod;
        // deb2(term,denom);
        // deb2(temp,k);
        denom=power(n,mod-2);
        fo(j,v[i].size()){
            res=(mapp[v[i][j]]*denom)%mod;
            res=(res*temp)%mod;

            ans=(ans+res)%mod;   
        }
    }

    
    cout<<ans<<nl;

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

