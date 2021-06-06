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
string next(string s){
    string rev;
    rev=s;
    reverse(all(rev));
    int i,j;
    fo(i,rev.size()){
        if(rev[i]!='z'){
            rev[i]++;
            for(j=i-1;j>=0;j--){
                rev[j]='a';
            }
            reverse(all(rev));
            return rev;
        }
    }
    fo(i,s.size()){
        s[i]='a';
    }
    s.pb('a');
    return s;
}
void solve(){
    int i,j;
    int n;
    cin>>n;
    string s,curr;
    cin>>s;
    curr.pb('a');
    int k=1000;
    while(true){
        // deb(curr);
        size_t found = s.find(curr);

        if(found==string::npos){
            break;
        }
        
        curr=next(curr);
        
        
    }

    
    cout<<curr<<nl;
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

