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
int LPP(string str)
{
 
    // Create temporary string
    string temp = str + '?';
 
    // Reverse the string str
    reverse(str.begin(), str.end());
 
    // Append string str to temp
    temp += str;
 
    // Find the length of string temp
    int n = temp.length();
 
    // lps[] array for string temp
    int lps[n];
 
    // Initialise every value with zero
    fill(lps, lps + n, 0);
 
    // Iterate the string temp
    for (int i = 1; i < n; i++) {
 
        // Length of longest prefix
        // till less than i
        int len = lps[i - 1];
 
        // Calculate length for i+1
        while (len > 0
               && temp[len] != temp[i]) {
            len = lps[len - 1];
        }
 
        // If character at current index
        // len are same then increment
        // length by 1
        if (temp[i] == temp[len]) {
            len++;
        }
 
        // Update the length at current
        // index to len
        lps[i] = len;
    }
 
    
    return lps[n - 1];
}
string find(string s){
    // deb(s);
    string a,b,ans;
    int i,n;
    a=s;
    b=s;
    reverse(all(b));
    if(LPP(a)>=LPP(b)){
        n=LPP(a);
        fo(i,n){
            ans.pb(a[i]);
        }
    }
    else{
        n=LPP(b);
        fo(i,n){
            ans.pb(b[i]);
        }
        reverse(all(ans));
    }
    return ans;
}
void solve(){
    int i,j;
    string s,a,b,c,ans;
    cin>>s;
    int n;
    n=s.size();
    i=0;
    j=n-1;
    while(i<j){
        // deb2(i,j);
        if(s[i]==s[j]){
            a.pb(s[i]);
            b.pb(s[j]);
        }
        else{
            break;
        }
        i++;
        j--;
    }
    reverse(all(b));
    if(i<=j){
        c=find(s.substr(i,j-i+1));
    }
    ans=a+c+b;
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

