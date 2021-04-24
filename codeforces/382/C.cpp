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
    int n;
    cin>>n;
    lli a[n],gap,x,y;
    map<lli,lli> mapp;
    vector<lli> v;
    fo(i,n){
        cin>>a[i];
    }
    if(n==1){
        cout<<"-1\n";
        return;
    }
    sort(a,a+n);
    if(a[0]==a[n-1]){
        cout<<1<<nl;
        cout<<a[0]<<nl;
        return;
    }
    fo(i,n-1){
        if(a[i]==a[i+1]){
            cout<<"0\n";
            return;
        }
    }
    
    for(i=1;i<n;i++){
        gap=a[i]-a[i-1];
        if(mapp[gap]==0){
            v.pb(gap);
        }
        mapp[gap]++;
    }
    if(v.size()>2){
        cout<<"0\n";
        return;
    }
    if(v.size()==1){
        if(n==2 && v[0]%2==0){
            cout<<3<<nl;
            gap=v[0];
            cout<<a[0]-gap<<" "<<(a[0]+a[1])/2<<" "<<a[1]+gap<<nl;
            return;
        }
        cout<<2<<nl;
        gap=v[0];
        cout<<a[0]-gap<<" "<<a[n-1]+gap<<nl;
    }
    else if(v.size()==2){
        x=min(v[0],v[1]);
        y=max(v[0],v[1]);
        if(2*x!=y || mapp[y]>1){
            cout<<"0\n";
            return;
        }
        cout<<1<<nl;
        gap=x;
        fo2(i,1,n-1){
            if(a[i]-a[i-1]==y){
                cout<<a[i]-x<<nl;
                break;
            }
        }
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
    return 0;
}

