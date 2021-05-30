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
    ll i,j,k,l,r;
    ll n,m,count;
    cin>>n>>m;
    string s;
    cin>>s;
    fo(i,n){
        if(s[i]=='1'){
            break;
        }
        if(i==n-1){
            cout<<s<<nl;
            return;
        }
    }
    ll start,end;
    fo(i,n){
        if(s[i]=='1'){
            start=i;
            break;
        }
    }
    fo(i,n){
        if(s[i]=='1'){
            end=i;
        }
    }
    for(i=end+1,count=0;i<n && count<m;i++,count++){
        s[i]='1';
    }
    for(i=start-1,count=0;i>=0 && count<m;i--,count++){
        s[i]='1';
    }
    // deb(s);
    fo2(i,start,end){
        if(s[i]=='1'){
            continue;
        }
        j=i;
        while(j<n && s[j]=='0'){
            j++;
        }
        l=i;r=j-1;count=0;
        while(l<r && count<m){
            s[l]='1';
            s[r]='1';
            l++;
            r--;
            count++;
        }
        i=j-1;
        
    }
    count=0;
    
    cout<<s<<nl;
  
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
}

