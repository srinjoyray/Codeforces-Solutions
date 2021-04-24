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
    int n,p;
    cin>>n>>p;
    string s;
    cin>>s;
    lli a[n/2],temp,ans,left,right;
    char c1,c2;
    fo(i,n/2){
        c1=s[i];
        c2=s[n-1-i];
        temp=abs(c1-c2);
        if(temp>13){
            temp=26-temp;
        }
        a[i]=temp;
    }
    if(n%2==0 ){
        if(p>=n/2){
            p=n-p;
        }
        else{
            p--;
        }
    }
    if(n%2==1 ){
        if(p==n/2){
            p=-1;
        }
        if(p<n/2){
            p--;
        }
        else{
            p=n-p;
        }
    }
    if(p==-1){
        temp=0;
        fo(i,n/2){
            temp+=1+a[i];
            if(a[i]>0){
                ans=temp;
            }
        }
        cout<<ans<<nl;
        return;
    }
    ans=0;
    fo(i,n/2){
        ans+=a[i];
    }
    left=p;
    for(j=p;j>=0;j--){
        if(a[j]>0){
            left=j;
        }
    }
    right=p;
    for(j=p;j<n/2;j++){
        if(a[j]>0){
            right=j;
        }
    }
    /*fo(i,n/2){
        cout<<a[i]<<" ";
    }cout<<nl;*/
    // deb(p);
    if(left<p && right >p){
        if((p-left)<=(right-p)){
            ans+=2*(p-left)+(right-p);
        }
        else{
            ans+=2*(right-p)+(p-left);
        }
    }
    else if(left<p){
        ans+=(p-left);
    }
    else if(right>p){
        ans+=(right-p);
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
    return 0;
}

