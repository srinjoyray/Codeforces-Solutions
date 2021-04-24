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
    lli i,j;
    string s;
    lli a,b,n,temp,dig;
    cin>>s;
    cin>>a>>b;
    n=s.size();
    lli pref[n+1]={0},suff[n+1]={0},pos=-1,rem,mult=1;
    temp=0;
    fo(i,n){
        dig=s[i]-'0';
        temp=temp*10 + dig;
        temp%=a;
        if(temp==0){
            pref[i+1]=1;
        }
    }
    temp=0;
    for(j=n-1,i=1;j>=0;j--,i++){
        dig=s[j]-'0';
        temp+=dig*mult;
        temp%=b;
        mult*=10;
        mult%=b;
        // deb(temp);
        if(temp==0){
            suff[i]=1;
        }
        
    }
    /*fo2(i,1,n){
        cout<<pref[i]<<" ";
    }cout<<nl;
    fo2(i,1,n){
        cout<<suff[i]<<" ";
    }cout<<nl;*/
    fo2(i,1,n-1){
        rem=n-i;
        if(pref[i]==1 && suff[rem]==1 && s[i]!='0'){
            pos=i;
            break;
        }
    }
    if(pos==-1){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    fo(i,pos){
        cout<<s[i];
    }cout<<nl;
    fo2(i,pos,n-1){
        cout<<s[i];
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

