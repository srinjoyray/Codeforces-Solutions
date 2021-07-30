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
    int i,j,k;
    int n,m;
    cin>>n>>m;
    string s,s1,s2,s3;
    cin>>s;
    int pref[3][3][n+1];
    memset(pref,0,sizeof pref);
    fo(i,n){
        if(i%3==0){
            s1.pb(s[i]);

        }
        else if(i%3==1){
            s2.pb(s[i]);
        }
        else{
            s3.pb(s[i]);
        }
        pref[i%3][s[i]-'a'][i+1]++;
    }
    fo(i,3){
        fo(j,3){
            fo2(k,1,n){
                pref[i][j][k]+=pref[i][j][k-1];
            }
        }
    }
    // deb2(s1,s2);
    // deb(s3);
    // fo(i,3){
    //     fo(j,3){
    //         fo(k,n+1){
    //             cout<<pref[i][j][k]<<" ";
    //         }
    //         cout<<"     ";
    //     }
    //     cout<<nl;
    // }
    while(m--){
        int l,r,ans,count,len,temp;
        cin>>l>>r;

        ans=INT_MAX;
        len=r-l+1;
        // abc
        count=0;
        count+=pref[0][0][r]-pref[0][0][l-1];
        count+=pref[1][1][r]-pref[1][1][l-1];
        count+=pref[2][2][r]-pref[2][2][l-1];
        temp=len-count;
        ans=min(ans,temp);
        // acb
        count=0;
        count+=pref[0][0][r]-pref[0][0][l-1];
        count+=pref[1][2][r]-pref[1][2][l-1];
        count+=pref[2][1][r]-pref[2][1][l-1];
        temp=len-count;
        ans=min(ans,temp);
        //bac
        count=0;
        count+=pref[0][1][r]-pref[0][1][l-1];
        count+=pref[1][0][r]-pref[1][0][l-1];
        count+=pref[2][2][r]-pref[2][2][l-1];
        temp=len-count;
        ans=min(ans,temp);

        //bca
        count=0;
        count+=pref[0][1][r]-pref[0][1][l-1];
        count+=pref[1][2][r]-pref[1][2][l-1];
        count+=pref[2][0][r]-pref[2][0][l-1];
        temp=len-count;
        ans=min(ans,temp);

        // cab
        count=0;
        count+=pref[0][2][r]-pref[0][2][l-1];
        count+=pref[1][0][r]-pref[1][0][l-1];
        count+=pref[2][1][r]-pref[2][1][l-1];
        temp=len-count;
        ans=min(ans,temp);
        // cba 
        count=0;
        count+=pref[0][2][r]-pref[0][2][l-1];
        count+=pref[1][1][r]-pref[1][1][l-1];
        count+=pref[2][0][r]-pref[2][0][l-1];
        temp=len-count;
        ans=min(ans,temp);
        cout<<ans<<nl;
    }
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
    
}

