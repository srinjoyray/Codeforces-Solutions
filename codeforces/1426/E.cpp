#include<bits/stdc++.h>
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define fo2(i,start,end) for(i=start;i<=end;i++)
#define rfo(i,n) for(i=n-1;i>=0;i--)
#define lli long long int
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
typedef pair<lli, lli>	pl;
typedef vector<int>		vi;
typedef vector<lli>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
void solve(){
    int i,j;
    ll n;
    cin>>n;
    ll mx,mn=1e12,temp;
    vl a(3),b(3),a1(3),b1(3);
    fo(i,3){
        cin>>a[i];
    }
    fo(i,3){
        cin>>b[i];
    }
    mx=min(b[0],a[2])+min(b[1],a[0])+min(b[2],a[1]);
    // deb(mx);
    
    vpii v;
    v.pb({0,0});
    v.pb({0,2});
	v.pb({1, 1});
	v.pb({1, 0});
	v.pb({2, 2});
	v.pb({2, 1});
    sort(all(v));
    // deb2(a[2],b[0]);
    do{
        a1=a;
        b1=b;
        fo(i,v.size()){
            temp=min(a1[v[i].F],b1[v[i].S]);
            a1[v[i].F]-=temp;
            b1[v[i].S]-=temp;
        }
        // deb2(a1[2],b1[0]);
        temp=min(b1[0],a1[2])+min(b1[1],a1[0])+min(b1[2],a1[1]);
        // deb(temp);
        mn=min(mn,temp);
    }while(next_permutation(all(v)));
    
    cout<<mn<<" "<<mx<<nl;
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

