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
int differ(string a,string b){
    int i,n,count=0;
    n=a.size();
    fo(i,n){
        if(a[i]!=b[i]){
            count++;
        }
    }
    return count;
}
void solve(){
    int i,j,k;
    int n,m;
    cin>>n>>m;
    string s[n],ans,temp;
    fo(i,n){
        cin>>s[i];
    }
    bool flag=false;
    ans=s[0];
    fo(i,m){
        temp=ans;
        fo(j,26){
            flag=true;
            temp[i]='a'+j;
            // deb(temp);
            fo2(k,1,n-1){
                if(differ(temp,s[k])>1){
                    flag=false;
                    break;
                }
            }
            if(flag==true){
                cout<<temp<<nl;
                return;
            }
        }
    }
    cout<<"-1\n";



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

