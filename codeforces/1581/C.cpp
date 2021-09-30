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

void solve(){
    int i,j,k,z;
    int n,m;
    cin>>n>>m;
    string s[n];
    fo(i,n){
        cin>>s[i];
    }
    int pref[n][m]={0},dig,curr,req,store[m],val,end[m],diff[m],pos[m],p1,mn,pref2[m],ans;
    ans=INT_MAX;
    fo(j,m){
        curr=0;
        fo(i,n){
            dig=s[i][j]-'0';
            curr+=dig;
            pref[i][j]=curr;
        }
    }
    // fo(i,n){
    //     fo(j,m){
    //         cout<<pref[i][j];
    //     }cout<<nl;
    // }cout<<nl;
    fo(i,n){
        fo2(k,i+4,n-1){
            memset(store,0,sizeof store);
            memset(end,0,sizeof end);
            memset(diff,0,sizeof diff);
            memset(pos,0,sizeof pos);
            memset(pref2,0,sizeof pref2);
            req=k-i-1;
            fo(j,m){
                val=pref[k][j]-pref[i][j];
                if(s[k][j]=='1'){
                    val--;
                }
                else{
                    val++;
                }
                if(s[i][j]=='0'){
                    val++;
                }
                store[j]=val;
                if(s[i][j]=='0'){
                    val--;
                }
                if(s[k][j]=='0'){
                    val--;
                }
                val=req-val;
                end[j]=val;
                diff[j]=end[j]-store[j];
            }
            fo(j,m){
                if(j==0){
                    pref2[j]=store[j];
                }
                else{
                    pref2[j]=pref2[j-1]+store[j];
                }
            }
            // fo(j,m){
            //     cout<<store[j];
            // }cout<<nl;
            // fo(j,m){
            //     cout<<end[j];
            // }cout<<nl;
            

            mn=1e5;
            curr=0;
            for(j=m-1;j>=0;j--){
                // deb(mn);
                if(end[j]<=store[j]+mn){
                    pos[j]=j;
                    mn=end[j];
                    p1=j;
                }
                else{
                    pos[j]=p1;
                    mn+=store[j];
                }
            }

            // fo(j,m){
            //     cout<<pos[j];
            // }cout<<nl;
            fo(j,m-3){
                z=j+3;
                z=pos[z];
                // deb2(j,z);
                val=end[j]+end[z]+pref2[z-1]-pref2[j];
                ans=min(ans,val);
            }

        }
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

