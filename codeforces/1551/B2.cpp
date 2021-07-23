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
    int a[n],b[n],rem,val,ans[n],count=0;
    bool flag;
    memset(ans,-1,sizeof ans);
    map<int,int> freq;
    vpii v;
    fo(i,n){
        cin>>a[i];
        b[i]=a[i];
        v.pb({a[i],i});
    }
    sort(b,b+n);
    sort(all(v));
    fo(i,n){
        freq[b[i]]++;
        if(freq[b[i]]>k){
            ans[i]=0;
        }
        else{
            count++;
        }
    }
    rem=count%k;
    count=0;
    val=1;    
    fo(i,n){
        if(ans[i]==0){
            continue;
        }
        count++;
        if(count<=rem){
            ans[i]=0;
            continue;
        }
        ans[i]=val;
        val++;
        if(val>k){
            val=1;
        }
    }
    int res[n];
    fo(i,n){
        res[v[i].S]=ans[i];
    }
    fo(i,n){
        cout<<res[i]<<" ";
    }cout<<nl;
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

