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
string s,t;
bool find(int p1,int p2){
    string curr;
    int i,j;
    for(i=p1;i<=p2;i++){
        curr+=s[i];
        if(curr.size()==t.size()){
            if(curr==t){
                return true;
            }
            else{
                return false;
            }
        }
    }

    for(i=p2-1;i>=0;i--){
        curr+=s[i];
        if(curr.size()==t.size()){
            if(curr==t){
                return true;
            }
            else{
                return false;
            }
        }
    }
    return false;
}
void solve(){
    int i,j;
    cin>>s>>t;
    int n=t.size();
    
    fo(i,s.size()){
        
        for(j=i;j<s.size();j++){
            if(find(i,j)){
                cout<<"YES\n";
                return;
            }
        }
    }
    cout<<"NO\n";
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

