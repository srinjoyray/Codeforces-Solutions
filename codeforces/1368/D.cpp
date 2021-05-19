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
string decToBinary(lli n)
{
    
    string binaryNum,s;
    int rem;
    // counter for binary array
    int i = 0;
    while (n > 0) {
 
        // storing remainder in binary array
        binaryNum.pb((n%2)+'0') ;
        n = n / 2;
        i++;
    }
    reverse(all(binaryNum));
    rem=22-binaryNum.size();
    fo(i,rem){
        s.pb('0');
    }
    return s+binaryNum;
}
lli toDecimal(string s){
    reverse(all(s));
    lli ans=0;
    for(int j=0;j<22;j++){
        if(s[j]=='1'){
            ans+=pow(2,j);
        }
    }
    return ans;
}
void solve(){
    int i,j;
    int n;
    cin>>n;
    lli a[n];
    string s[n],temp;
    vl v;
    fo(i,n){
        cin>>a[i];
        // deb(a[i]);
        s[i]=decToBinary(a[i]);
        // deb(s[i]);
    }
    int freq[22]={0};
    fo(i,n){
        fo(j,22){
            if(s[i][j]=='1'){
                freq[j]++;
            }
        }
    }
    fo(j,22){
        temp.pb('0');
        // cout<<freq[j]<<" ";
    }cout<<nl;
    bool flag=true;
    
    while(flag){
        flag=false;
        fo(j,22){
            if(freq[j]>0){
                temp[j]='1';
                freq[j]--;
                flag=true;
            }
            else{
                temp[j]='0';
            }
        }
        v.pb(toDecimal(temp));
    }
    lli ans=0;
    fo(i,v.size()){
        ans+=v[i]*v[i];
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

