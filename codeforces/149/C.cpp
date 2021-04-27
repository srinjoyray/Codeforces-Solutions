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
bool comp(pii a,pii b){
    if(a.F==b.F){
        a.S<b.S;
    }
    return a.F>b.F;
}
void solve(){
    int i,j;
    int n;
    cin>>n;
    vpii a;
    int temp,sumx=0,sumy=0;
    vector<int> vx,vy;
    fo(i,n){
        cin>>temp;
        a.pb({temp,i+1});
        // deb(a[i]);
    }
    sort(all(a),comp);
    for(i=0;i<n;i+=2){
        if(i==n-1){
            // deb2(sumx,sumy);
            if(sumx<=sumy){
                vx.pb(a[i].S);
            }
            else{
                vy.pb(a[i].S);
            }
            break;
        }
        if(sumx<=sumy){
            vx.pb(a[i].S);
            vy.pb(a[i+1].S);
            sumx+=a[i].F;
            sumy+=a[i+1].F;
        }
        else{
            vy.pb(a[i].S);
            vx.pb(a[i+1].S);
            sumy=a[i].F;
            sumx=a[i+1].F;
        }
    }
    cout<<vx.size()<<nl;
    fo(i,vx.size()){
        cout<<vx[i]<<" ";
    }cout<<nl;
    cout<<vy.size()<<nl;
    fo(i,vy.size()){
        cout<<vy[i]<<" ";
    }cout<<nl;
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
    return 0;
}

