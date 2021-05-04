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
    double h,c,t,mid,gap,temp1,temp2;
    lli ans,l,r;
    cin>>h>>c>>t;
    mid=(h+c)/2;
    if(t<=mid){
        ans=2;
        cout<<ans<<nl;
        return;
    }
    else{
        gap=t-mid;
        // deb2(mid,gap);
        // deb((h-mid)/gap);
        l=floor((h-mid)/gap);
        if(l%2==0){
            l--;
        }
        r=l+2;
        temp1=((r-1)*mid + h)/r;
        temp2=((l-1)*mid+ h)/l;
        if(abs(t-temp2)<=abs(t-temp1) && l>0){
            ans=l;
        }
        else{
            ans=r;
        }
        cout<<ans<<nl;
    }

    /*
     (mid*(ans-1)+h)/ans=
    */
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
    return 0;
}

