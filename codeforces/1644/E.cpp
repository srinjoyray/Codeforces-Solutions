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
ll helper(string s,ll n){
    ll i,j,r;
  
    r= n-count(all(s),'R')-1;

   
    // deb(s);
    ll row=1,col=1,left=0,found=0;
    fo(i,s.size()){
        if(s[i]=='D'){
            left += n-col;
            row++;
        }
        else{
            if(found==0){
                col+=r;
                found=1;
            }
            col++;
        }
    }
    // deb(left);
    return left;
}
void solve(){
    int i,j;
    ll n;
    cin>>n;
    string s,oppo,s1;
    cin>>s;
    s1=s;
    fo(i,s.size()){
        if(s[i]=='R'){
            oppo.pb('D');
        }
        else{
            oppo.pb('R');
        }
    }
    sort(all(s1));
    if(s1[0]==s1[s1.size()-1]){
        cout<<n<<nl;
        return;
    }
    ll ans;
    ans = n*n - (helper(s,n)+helper(oppo,n));
    
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

