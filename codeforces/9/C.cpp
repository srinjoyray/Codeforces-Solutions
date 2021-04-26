#include<bits/stdc++.h>
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define fo2(i,start,end) for(i=start;i<=end;i++)
#define rfo(i,n) for(i=n-1;i>=0;i--)
#define lli long long int
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
typedef pair<lli, lli>	pl;
typedef vector<int>		vi;
typedef vector<lli>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
string to_binary(lli n)
{   string s;
    int binaryNum[30]={0};
    int rem;
    int i = 0;
    while (n > 0) {
 
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    for (int j = i - 1; j >= 0; j--)
        s.pb(binaryNum[j]+'0');
    
    return s;
}
lli to_decimal(string s){
    lli ans=0;
    int i;
    reverse(s.begin(),s.end());
    fo(i,s.size()){
        if(s[i]=='1'){
            ans+=pow(2,i);
        }
    }
    return ans;
}
void solve(){
    int i,j;
    lli n,dig=0,ans=0,temp,num,dec;
    string s;
    cin>>n;
    temp=n;
    while(temp){
        temp/=10;
        dig++;
    }
    ans=pow(2,dig-1)-1;
    num=pow(10,dig-1);
    s=to_string(num);
    dec=to_decimal(s);
    // deb(ans);
    while(true){
        s=to_binary(dec);
        // deb2(dec,s);
        num=stoll(s);
        if(num>n){
            break;
        }
        else{
            ans++;
        }
        dec++;
    }
    cout<<ans<<nl;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

