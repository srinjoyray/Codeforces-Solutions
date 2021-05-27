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
    int n,a[6];
    fo(i,6){
        cin>>a[i];
    }
    cin>>n;
    int b[n],temp,ans=INT_MAX,ind;
    fo(i,n){
        cin>>b[i];
    }
    vi v[n];
    fo(j,n){
        fo(i,6){
            temp=abs(a[i]-b[j]);
            v[j].pb(temp);
        }    
    }
    fo(i,n){
        sort(all(v[i]));
    }
    set<pii> se;
    fo(i,n){
        se.insert({v[i][0],i});
    }
    map<int,int> index;
    while(true){
        temp=abs((*se.begin()).F-(*se.rbegin()).F);
        ans=min(ans,temp);
        ind=(*se.begin()).S;
        index[ind]++;
        se.erase(se.begin());
        if(index[ind]>=v[ind].size()){
            break;
        }
        temp=v[ind][index[ind]];
        se.insert({temp,ind});   
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

