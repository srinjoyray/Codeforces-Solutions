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
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    int a[n];
    fo(i,n){
        if(s[i]=='+'){
            a[i]=1;
        }
        else{
            a[i]=-1;
        }
    }
    int pmax[n+1]={0},pmin[n+1]={0},sum[n+1]={0},smin[n+1]={0},smax[n+1]={0};

    int curr=0,mx=0,mn=0;
    fo(i,n){
        curr+=a[i];
        mx=max(mx,curr);
        mn=min(mn,curr);

        pmax[i+1]=mx;
        pmin[i+1]=mn;
        sum[i+1]=curr;
    }

    mx=curr; mn=curr;

    for(i=n-1;i>=0;i--){
        mx=max(mx,curr);
        mn=min(mn,curr);
        // deb2(mx,mn);
        smax[i+1]=mx;
        smin[i+1]=mn;
        curr-=a[i];
    }
    /*fo2(i,1,n){
        cout<<smax[i]<<" ";
    }cout<<nl;*/
    while(m--){
        int l,r,temp,mn1=0,mn2=0,mx1=0,mx2=0;
        cin>>l>>r;
        temp=sum[r]-sum[l-1];
        // deb(temp);
        if(l>1){
            mn1=min(mn1,pmin[l-1]);
            mx1=max(mx1,pmax[l-1]);
            // deb2(mn1,mx1);
        }
        if(r<n){
            mn2=min(mn2,smin[r+1]-temp);
            mx2=max(mx2,smax[r+1]-temp);
            // deb2(mn2,mx2);
        }
        mn=min(mn1,mn2);
        mx=max(mx1,mx2);
        cout<<mx-mn+1<<nl;
    }
   
   

    
    
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

