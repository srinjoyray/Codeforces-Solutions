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
    int i,j,k;
    int n;
    cin>>n;
    string s[n];
    fo(i,n){
        cin>>s[i];
    }
    vpii v1,v2;
    int mn,mx,base,ht,temp,ans; 
    for(int k=0;k<=9;k++){
        v1.clear();
        fo(i,n){
            fo(j,n){
                if(s[i][j]=='0'+k){
                    v1.pb({i+1,j+1});
                }
            }
        }
        sort(all(v1));
        if(v1.size()<2){
            cout<<"0 ";
            continue;
        }
        mn=v1[0].F; mx=v1[v1.size()-1].F;
        ans=0;
        fo(i,v1.size()){
            base=max(v1[i].F-mn,mx-v1[i].F);
            ht=max(v1[i].S-1,n-v1[i].S);
            temp=base*ht;
            ans=max(ans,temp);
        }

        v2.clear();
        fo(i,n){
            fo(j,n){
                if(s[i][j]=='0'+k){
                    v2.pb({j+1,i+1});
                }
            }
        }
        sort(all(v2));
        mn=v2[0].F; mx=v2[v2.size()-1].F;
        fo(i,v2.size()){
            base=max(v2[i].F-mn,mx-v2[i].F);
            ht=max(v2[i].S-1,n-v2[i].S);
            temp=base*ht;
            ans=max(ans,temp);
        }
        cout<<ans<<" ";
    }
    cout<<nl;
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

