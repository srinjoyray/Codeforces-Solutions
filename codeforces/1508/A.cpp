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
string solve1(string a,string b,char type){
    string s="";
    int n,i,j;
    n=a.size();
    i=0;j=0;
    while(i<n && j<n){
        if(a[i]==type){
            while(j<n && b[j]!=type){
                s.pb(b[j]);
                j++;
            }
            s.pb(a[i]);
            i++;
            j++;
        }
        else{
            s.pb(a[i]);
            i++;
        }
        
    }

    while(i<n){
        s.pb(a[i]);
        i++;
    }
    while(j<n){
        s.pb(b[j]);
        j++;
    }

    while(s.size()<(3*n)/2){
        s.pb('0');
    }
    return s;
}
void solve(){
    int i,j;
    int n;
    cin>>n;
    string s,a,b,c;
    cin>>a>>b>>c;
    int A=0,B=0,C=0;
    fo(i,2*n){
        if(a[i]=='1'){
            A++;
        }
        if(b[i]=='1'){
            B++;
        }
        if(c[i]=='1'){
            C++;
        }
    }

    if(A<=n && B<=n){
        s=solve1(a,b,'0');
    }
    else if(A>=n && B>=n){
        s=solve1(a,b,'1');
    }
    else if(B<=n && C<=n){
        s=solve1(b,c,'0');
    }
    else if(B>=n && C>=n){
        s=solve1(b,c,'1');
    }
    else if(A<=n && C<=n){
        s=solve1(a,c,'0');
    }
    else if(A>=n && C>=n){
        s=solve1(a,c,'1');
    }
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

