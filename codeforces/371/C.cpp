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
void solve(){
    int i,j;
    string str;
    cin>>str;
    lli bread,sausage,cheese,pb,ps,pc,b=0,s=0,c=0,total,ans=0,temp;
    cin>>bread>>sausage>>cheese>>pb>>ps>>pc;
    lli r;
    cin>>r;
    fo(i,str.size()){
        if(str[i]=='B'){
            b++;
        }
        if(str[i]=='C'){
            c++;
        }
        if(str[i]=='S'){
            s++;
        }
    }
    if(b==0){
        bread=0;
    }
    if(c==0){
        cheese=0;
    }
    if(s==0){
        sausage=0;
    }
    while(bread>0 || sausage>0 || cheese>0){
        temp=0;
        if(b>0){
            if(bread>=b){
                bread-=b;
            }
            else{
                temp+=pb*(b-bread);
                bread=0;
            }
        }
        if(c>0){
            if(cheese>=c){
                cheese-=c;
            }
            else{
                temp+=pc*(c-cheese);
                cheese=0;
            }
        }
        if(s>0){
            if(sausage>=s){
                sausage-=s;
            }
            else{
                temp+=ps*(s-sausage);
                sausage=0;
            }
        }
        if(temp<=r){
            r-=temp;
            ans++;
        }
        else{
            break;
        }
    }
    total=b*pb+c*pc+s*ps;
    ans+=r/total;
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

