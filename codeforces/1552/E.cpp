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
    int n,k,m,val;
    cin>>n>>k;
    m=n*k;
    val=(n+k-2)/(k-1);
    // deb(val);
    int a[m+1],b[m+1]={0};
    fo2(i,1,m){
        cin>>a[i];
    }
    map<int,int> mapp;
    set<int> se;
    map<int,pii> ans;
    fo2(i,1,m){
        // deb2(a[i],mapp[a[i]]);
        if(se.find(a[i])!=se.end()){
            continue;
        }
        if(mapp[a[i]]==0){
            mapp[a[i]]=i;
            continue;
        }
        for(j=mapp[a[i]];j<=i;j++){
            if(b[j]>=val){
                break;
            }
        }
        // deb2(j,i);
        if(j!=i+1){
            mapp[a[i]]=i;
            continue;
        }
      
        ans[a[i]]={mapp[a[i]],i};
        se.insert({a[i]});
        for(j=mapp[a[i]];j<=i;j++){
            b[j]++;
        }
    }
    fo2(i,1,n){
        cout<<ans[i].F<<" "<<ans[i].S<<nl;
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

