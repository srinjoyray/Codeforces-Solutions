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
string to_binary(int n){
    int binaryNum[32]={0};
    string s;
    int i=0,j;
    while(n>0){
        binaryNum[i] = n % 2;
        n=n/2;
        i++;
    }
    fo(j,32){
        s.pb(binaryNum[j]+'0');
    }
    reverse(all(s));
    return s;
}
ll to_decimal(string s){
    ll i,ans=0;
    reverse(all(s));;
    fo(i,32){
        if(s[i]=='1'){
            ans+=pow(2,i);
        }
    }
    return ans;

}
void solve(){
    int i,j;
    ll n,m,m_temp,start,val,temp;
    cin>>n>>m;
    m+=1;
    string s1,s2,s3;
    s1=to_binary(n);
    s2=to_binary(m);
    fo(i,32){
        s3.pb('0');
    }
    // deb(s1);
    // deb(s2);
    ll ans;
    fo(i,32){
        if(s1[i]==s2[i]){
            s3[i]='0';
        }
        if(s1[i]=='1' && s2[i]=='0'){
            s3[i]='0';
            break;
        }
        if(s1[i]=='0' && s2[i]=='1'){
            s3[i]='1';
        }
    }
    

    // deb(s3);
    ans=to_decimal(s3);
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

