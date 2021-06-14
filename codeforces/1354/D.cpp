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
vi a,k;
int check(int x){
    int i,count=0;
    fo(i,a.size()){
        if(a[i]<=x){
            count++;
        }
    }
    fo(i,k.size()){
        if(k[i]>0 && k[i]<=x){
            count++;
        }
        if(k[i]<0 && abs(k[i])<=count){
            count--;
        }
    }
    return count;
}
void solve(){
    int i,j;
    int n,q;
    cin>>n>>q;
    a.resize(n);
    k.resize(q);
    fo(i,n){
        cin>>a[i];
    }
    fo(i,q){
        cin>>k[i];
    }
    
    if(check(1e6+1)==0){
        cout<<"0\n";
        return;
    }

    int l,r,mid,ans;
    l=0;
    r=1e6+1;
    while(l<=r){
        mid=(l+r)/2;
        if(check(mid)>0){
            r=mid-1;
            ans=mid;
        }
        else{
            l=mid+1;
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

