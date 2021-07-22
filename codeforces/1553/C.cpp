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
const int N=1e6+10;
int find(string s){
    int i,one=0,two=0,rem;
    // deb(s);
    fo(i,10){
        rem=(10-i)/2;
        
        // deb(rem);
        if(i%2==0){
            if(s[i]=='1'){
                one++;
            }
            if(one>two+rem){
                return i+1;
            }
            if(one+rem-1<two){
                return i+1;
            }
        }
        else{
            if(s[i]=='1'){
                two++;
            }
            if(two>one+rem){
                return i+1;
            }
            if(two+rem<one){
                return i+1;
            }
            
        }
        // deb2(one,two);
    }
    return 10;
}
void solve(){
    int i,j;
    string s,s1,s2;
    cin>>s;
    s1=s;
    s2=s;
    int ans;
    fo(i,10){
        if(s1[i]=='?'){
            if(i%2==0){
                s1[i]='1';
            }
            else{
                s1[i]='0';
            }
        }
    }
    fo(i,10){
        if(s2[i]=='?'){
            if(i%2==1){
                s2[i]='1';
            }
            else{
                s2[i]='0';
            }
        }
    }
    // deb(find(s1));
    // deb(find(s2));
    ans=min(find(s1),find(s2));
    cout<<ans<<nl;
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

