#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fo(i,n) for(i=0;i<n;i++)
#define fo2(i,start,end) for(i=start;i<=end;i++)
#define rfo(i,n) for(i=n-1;i>=0;i--)
#define deb(x) cout<<#x<<"="<<x<<endl
#define deb2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
#define ll long long
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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

const int N=1e6+10;
int a[2][N];
int n;
string x,y;
void find(int i,int j){
    // deb2(i,j);
    if(a[i][j]!=-1){
        return;
    }
    a[i][j]=1;
    if(i==0){
        if(j<n-1 && x[j+1]=='0'){
            find(i,j+1);
        }
        if(y[j]=='0'){
            find(i+1,j);
        }
        if(j<n-1 && y[j+1]=='0'){
            find(i+1,j+1);
        }
    }
    else{
        if(j<n-1 && y[j+1]=='0'){
            find(i,j+1);
        }
        if(x[j]=='0'){
            find(i-1,j);
        }
        if(j<n-1 && x[j+1]=='0'){
            find(i-1,j+1);
        }
    }
}
void solve(){
    int i,j;
    
    cin>>n;
    
    cin>>x>>y;
    memset(a,-1,sizeof a);
    if(x[0]=='0'){
        find(0,0);
    }
    if(a[1][n-1]==1){
        cout<<"YES\n";
    }   
    else{
        cout<<"NO\n";
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
    
}

