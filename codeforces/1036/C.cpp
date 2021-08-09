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
ll fact[19];
ll ncr(ll n , ll r){
    ll ans=fact[n]/(fact[n-r]*fact[r]);
    return ans;
}
ll helper(ll dig,ll count){
    ll ans=1;
    // deb2(dig,count);
    if(count>3){
        return 0;
    }
    // if(count==3 || dig==0){
    //     return 1;
    // }
    if(count<=2 && dig>=1){
        ans+=ncr(dig,1)*9;
    }
    if(count<=1 && dig>=2){
        ans+=ncr(dig,2)*9*9;
    }
    if(count==0 && dig>=3){
        ans+=ncr(dig,3)*9*9*9;
    }
    
    // deb(ans);
    return ans;
}
ll find(string s){
    ll ans=0,temp,i,j;
    int count=0,n;
    n=s.size();
    fo(i,n){
        int dig=s[i]-'0';
        if(dig>0){
            ans+=helper(n-i-1,count);
            ans+=(dig-1)*helper(n-i-1,count+1);
            count++;
        }
        // deb(ans);
    }
    if(count<=3){
        ans++;
    }
    return ans;

}


void solve(){
    int i,j;
    ll l,r,ans=0,temp1=0,temp2=0;
    cin>>l>>r;
    string l1,r1;
    l1=to_string(l-1);
    r1=to_string(r);
    temp1=find(r1);
    temp2=find(l1);
    ans=temp1-temp2;
    // deb2(temp1,temp2);
    cout<<ans<<nl;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t=1;
    cin>>t;
    fact[0]=fact[1]=1;
    for(int i=2;i<19;i++){
        fact[i]=fact[i-1]*i;
    }
    while(t--){
        solve();
    }
    
}

