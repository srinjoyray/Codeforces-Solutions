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

void solve(){
    int i,j;
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    int x=0,y=0,x_plus=0,x_minus=0,y_plus=0,y_minus=0;
    fo(i,s.size()){
        if(s[i]=='R'){
            x++;
        }
        else if(s[i]=='L'){
            x--;
        }
        else if(s[i]=='U'){
            y++;
        }
        else {
            y--;
        }
        x_plus=max(x_plus,x);
        x_minus=max(x_minus,-x);
        y_plus=max(y_plus,y);
        y_minus=max(y_minus,-y);

        if(x_plus+x_minus>=m){
            if(s[i]=='R'){
                x_plus--;
            }
            else{
                x_minus--;
            }
            break;
        }
        if(y_plus+y_minus>=n){
            if(s[i]=='U'){
                y_plus--;
            }
            else{
                y_minus--;
            }
            break;
        }
    }
    // deb2(x_plus,x_minus);
    // deb2(y_plus,y_minus);
    cout<<y_plus+1<<" "<<x_minus+1<<nl;
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

