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
lli to_digit(string s){
    lli n,ans=0,i,j,rem,prev,d;
    n=s.size();
    for(i=1;i<n;i++){
        d=1;
        for(j=1;j<=i;j++){
            d*=26;
        }
        ans+=d;
    }
    // deb(ans);
    fo(i,n){
        rem=n-i-1;
        prev=s[i]-'A';
        d=1;
        for(j=1;j<=rem;j++){
            d*=26;
        }
        ans+=prev*d;
    }
    return ans+1;
}
string convert(lli num){
    string s;
    lli i,j,n,temp=0,rem,add,d;
    i=0;
    while(temp<num){
        i++;
        
        d=1;
        for(j=1;j<=i;j++){
            d*=26;
        }
        temp+=d;
        // deb2(temp,d);
    }
    // deb(temp);
    temp-=pow(26,i);
    // deb(temp);
    rem=num-temp;
    n=i;
    fo(i,n){
        s.pb('A');
    }
    fo(i,n){
        temp=n-i-1;
        d=1;
        for(j=1;j<=temp;j++){
            d*=26;
        }
        temp=d;
        // deb2(rem,temp);
        add=rem/temp;
        rem=rem%temp;
        // deb2(add,rem);
        s[i]+=add;
        // deb(s[i]);
    }
    for(j=n-1;j>=0;j--){
        if(s[j]=='A'){
            s[j]='Z';
        }
        else{
            s[j]--;
            break;
        }
    }
    return s;
}
void solve(){
    int i,j;
    string s,a,b,ans;
    cin>>s;
    lli n,row,col,val;
    n=s.size();
    bool flag=false;
    fo2(i,1,n-2){
        if(s[i]>='0' && s[i]<='9' && (s[i+1]<'0' || s[i+1]>'9')){
            flag=true;
            break;
        }
    }
    if(flag){
        fo2(i,1,n-1){
            if(s[i]=='C'){
                break;
            }
            else{
                a.pb(s[i]);
            }
        }
        i++;
        while(i<n){
            b.pb(s[i]);
            i++;
        }
        row=stoll(a);
        col=stoll(b);
        ans=convert(col);
        cout<<ans<<row<<nl;
    }
    else{
        fo(i,n){
            if(s[i]>='0' && s[i]<='9'){
                break;
            }
            else{
                a.pb(s[i]);
            }
        }
        while(i<n){
            b.pb(s[i]);
            i++;
        }
        row=stoll(b);
        col=to_digit(a);
        cout<<"R"<<row<<"C"<<col<<nl;
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
    return 0;
}

