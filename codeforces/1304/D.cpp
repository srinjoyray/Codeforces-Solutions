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

void solve(){
    int i,j;
    int n;
    cin>>n;
    string s;
    cin>>s;
    int a[n],b[n],val;
    memset(a,-1,sizeof a);
    memset(b,-1,sizeof b);

    val=1;
    fo(i,n-1){
        if(s[i]=='<'){
            a[i]=val;
            val++;
        }
    }
    fo(i,n){
        if(i==n-1 && a[i]==-1){
            j=i;
            while(j>=0 && a[j]==-1){
                a[j]=val;
                val++;
                j--;
            }
        }
        else if(i<n-1 && a[i]==-1 && a[i+1]!=-1){
            j=i;
            while(j>=0 && a[j]==-1){
                a[j]=val;
                val++;
                j--;
            }
        }
    }
    
    val=1;
    for(i=n-2;i>=0;i--){
        if(b[i]!=-1){
            continue;
        }
        if(s[i]=='<'){
            j=i;
            while(j>=0 && s[j]=='<'){
                j--;
            }
            j++;
            // deb2(j,val);
            while(j<=i){
                b[j]=val;
                val++;
                j++;
            }
        }
    }
    val=n;
    fo(i,n){
        if(b[i]==-1){
            b[i]=val;
            val--;
        }
    }

    fo(i,n){
        cout<<b[i]<<" ";
    }cout<<nl;

    fo(i,n){
        cout<<a[i]<<" ";
    }cout<<nl;
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

