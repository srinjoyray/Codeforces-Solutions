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
    int n,k;
    cin>>n>>k;
    int x[k],y[k],sz,count,ans=0;
    set<int> se;
    map<int,int> mapp;
    vi v;
    fo(i,k){
        cin>>x[i]>>y[i];
        se.insert(x[i]);
        se.insert(y[i]);
        mapp[x[i]]=y[i];
        mapp[y[i]]=x[i];
    }

    fo2(i,1,2*n){
        if(se.find(i)==se.end()){
            v.pb(i);
        }
    }

    sz=v.size();
    // fo(i,sz){
    //     cout<<v[i]<<" ";
    // }cout<<nl;
    fo(i,sz/2){
        mapp[v[i]]=v[sz/2+i];
        mapp[v[sz/2+i]]=v[i];
    }
    fo2(i,1,2*n){
        int mn,mx;
        mn=min(i,mapp[i]);
        mx=max(i,mapp[i]);
        count=0;
        // deb2(mn,mx);
        for(j=mn+1;j<=mx-1;j++){
            if(mapp[j]>mx || mapp[j]<mn){
                count++;
            }
        }
        ans+=count;
        // deb2(i,count);
    }
    ans/=4;
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

