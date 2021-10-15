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
int n,a,b;
string s,s1="";
int dp[41][41][41][41];
bool solve(int idx,int mod_a,int mod_b,int rem_a){
    if(dp[idx][mod_a][mod_b][rem_a]!=-1){
        return dp[idx][mod_a][mod_b][rem_a];
    }
    
    if(idx==n){
        // deb2(mod_b,mod_a);
        if(mod_a==0 && mod_b==0){
            return true;
        }
        return false;
    }
    int i,rem_b,temp,dig;
    rem_b=n-idx-rem_a;  
    dig=s[idx]-'0';

    // deb2(idx,dig);
    // deb2(mod_a,mod_b);
    // deb2(rem_a,rem_b);
    if(rem_a>0){
        temp=(mod_a*10+dig)%a;
        s1.pb('R');
        if(solve(idx+1,temp,mod_b,rem_a-1)){
            return dp[idx][mod_a][mod_b][rem_a]=true;
        }
        s1.pop_back();
    }
    if(rem_b>0){
        temp=(mod_b*10+dig)%b;
        s1.pb('B');
        if(solve(idx+1,mod_a,temp,rem_a)){
            return dp[idx][mod_a][mod_b][rem_a]=true;
        }
        s1.pop_back();
    }

    return dp[idx][mod_a][mod_b][rem_a]=false;
}
void solve(){
    int i,j;
    
    cin>>n>>a>>b;
    
    cin>>s;
     
    memset(dp,-1,sizeof dp);
    // solve(0,0,0,3);
    int gap=n+1,temp,ans=-1;
    fo2(i,1,n-1){
        if(solve(0,0,0,i)){
            temp=abs(i-(n-i));
            if(temp<gap){
                gap=temp;
                ans=i;
            }
        }
    }
    if(ans>=0){
        // deb(ans);
        memset(dp,-1,sizeof dp);
        s1="";
        solve(0,0,0,ans);
        // deb(s1);
        cout<<s1<<nl;
    }
    else{
        cout<<"-1\n";
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

