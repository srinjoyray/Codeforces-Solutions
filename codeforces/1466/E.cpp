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
ll power(ll a,ll n){
    ll res=1;
    while(n){
        if(n%2){
            res=(res*a)%mod;
        }
        n/=2;
        a=(a*a)%mod;
    }
    return res;
}
string to_binary(ll n){
    string s;
    while (n > 0) {
        int dig = n % 2;
        if(dig){
            s.pb('1');
        }
        else{
            s.pb('0');
        }
        n = n / 2;
    }
    reverse(all(s));
    int rem=60-s.size(),i;
    fo(i,rem){
        s='0'+s;
    }
    return s;
}
void solve(){
    int i,j;
    int n;
    cin>>n;
    string s[n];
    ll input;
    fo(i,n){
        // input=i%2;
        cin>>input;
        s[i]=to_binary(input);
        // deb(s[i]);
    }

    ll pref[61]={0};
    fo(i,n){
        fo(j,60){
            if(s[i][j]=='1'){
                pref[j]++;
            }
        }
    }
    
    ll p[60];
    fo(i,60){
        p[i]=power(2,60-i-1);
    }
    ll ans=0,count1,count2,temp;
    fo(i,n){
        count1=0;
        count2=0;
        fo(j,60){
            temp=p[j];
            if(s[i][j]=='0'){
                count1+=pref[j]*temp;
            }
            else{
                // deb(temp);
                count1+=n*temp;
                count2+=pref[j]*temp;
            }
            count1%=mod;
            count2%=mod;
        }
        // deb2(count1,count2);
        ans=(ans+(count1*count2)%mod)%mod;
    }
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

