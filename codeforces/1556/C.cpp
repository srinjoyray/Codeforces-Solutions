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
ll find(ll start,ll end,ll l,ll r){
    if(start>end){
        swap(start,end);
    }
    // deb2(l,r);
    // deb2(start,end);
    ll temp;
    if(start>r || end<l){
        return 0;
    }
    if(start>=l && end<=r){
        return abs(start-end)+1;
    }
    if(start<=l){
        temp=min(r,end);
        return (temp-l)+1;
    }
    if(end>=r){
        temp=max(start,l);
        return (r-temp)+1;
    }
    
    return 0;
}
void solve(){
    int i,j;
    int n;
    cin>>n;
    ll a[n],ans=0,l,r,sum=0,end,start,temp;
    fo(i,n){
        cin>>a[i];
    }
    for(i=0;i<n;i+=2){
        l=0;
        r=a[i]-1;
        sum=0;

        for(j=i+1;j<n;j+=2){            
            sum+=a[j-1];

            start=sum;
            sum-=a[j];
            end=sum;
            temp=find(start-1,end,l,r);
            // deb(temp);
            ans+=temp;
            r=min(r,sum);
            if(r<l){
                break;
            }
            // deb(sum);
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

