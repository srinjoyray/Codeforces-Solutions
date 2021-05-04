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
lli calc(lli f,lli cs,lli cw,lli s,lli w){
    lli temp,rem,req,ans=0;
    if(s<=w){
        req=min(f/s,cs);
        ans+=req;
        temp=f-req*s;
        req=min(temp/w,cw);
        ans+=req;
    }
    else{
        req=min(f/w,cw);
        ans+=req;
        temp=f-req*w;
        req=min(temp/s,cs);
        ans+=req;
    }
    return ans;
}
void solve(){
    int i,j;
    lli p,f,cs,cw,s,w,n;
    cin>>p>>f;
    cin>>cs>>cw;
    cin>>s>>w;
    vl v;
    lli temp1,temp2,rem,req,ts,tw,temp,mx=0;
    n=cw+cs;
    
    fo2(i,0,cs){
        temp1=i;
        if(temp1*s>p){
            break;
        }
        rem=p-temp1*s;
        req=rem/w;
        req=min(req,cw);
        temp1+=req;


        ts=cs-i;
        tw=cw-req;
        temp2=calc(f,ts,tw,s,w);

        temp=temp1+temp2;

        // deb2(i,temp);
        // deb2(temp1,temp2);
        mx=max(mx,temp);

    }
    cout<<mx<<nl;


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

