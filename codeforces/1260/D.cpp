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
const int N = 1e6;
int m,n,k,t,a[N],l[N],r[N],d[N];

bool possible(int val){
    // deb(val);
    int i,j,upto;
    if(val==0){
        return true;
    }
    upto=a[val-1];
    set<pii> se;
    fo(i,k){
        if(d[i]>upto){
            se.insert({l[i],r[i]});
        }
    }
    // for(auto itr : se){
    //     cout<<itr.F<<" "<<itr.S<<nl;
    // }
    int start,end,ans=n+1;
    while(se.size()){
        start=(*se.begin()).F;
        end=(*se.begin()).S;
        while(se.size() && (*se.begin()).F<=end){
            end=max(end,(*se.begin()).S);
            se.erase(se.begin());
        }
        // deb2(start,end);
        ans+=(end-start+1)*2;
    }

    // deb(ans);
    if(ans<=t){
        return true;
    }
    return false;
}

void solve(){
    int i,j;
    cin>>m>>n>>k>>t;

    fo(i,m){
        cin>>a[i];
    }
    fo(i,k){
        cin>>l[i]>>r[i]>>d[i];
    }
    sort(a,a+m,greater<int>());
    int low,mid,high,ans=0;

    low=0;
    high=m;

    while(low<=high){
        mid=(low+high)/2;
        // deb2(low,high);
        // deb(mid);
        if(possible(mid)){
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
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

