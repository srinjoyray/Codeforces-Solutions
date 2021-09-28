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
    // deb(n);
    int a[n],sum=0;
    pii l,r;
    vpii v;
    set<pii> se;
    fo(i,n){
        cin>>a[i];
        if(a[i]>0){
            se.insert({a[i],i+1});
        }
        
    }
    // deb(se.size());
    while(se.size()>1){
        l=*se.begin();
        se.erase(se.begin());
        r=*se.rbegin();
        se.erase(se.find(r));
        // deb2(l.F,r.F);
        l.F--;
        r.F--;
        if(l.F>0){
            se.insert(l);
        }
        if(r.F>0){
            se.insert(r);
        }
        // deb(se.size());
        v.pb({l.S,r.S});
    }

    cout<<v.size()<<nl;
    fo(i,v.size()){
        cout<<v[i].F<<" "<<v[i].S<<nl;
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
    
}

