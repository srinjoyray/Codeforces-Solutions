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
void solve(){
    int i,j;
    int n;
    cin>>n;
    int a[n],freq[n+1]={0},left,right;
    fo(i,n){
        cin>>a[i];
        freq[a[i]]++;
    }
    
    vector<bool> ans(n, false);
    if(freq[1]>=1){
        ans[n-1]=true;
    }
    fo2(i,1,n){
        if(freq[i]!=1){
            break;
        }
        if(i==n){
            ans[0]=true;
        }
    }
    left=0;right=n-1;
    for(i=2;i<=n;i++){
        if(freq[i]>=1 && freq[i-1]==1){
            if(a[left]==i-1){
                left++;
                ans[n-i]=true;
                freq[i-1]--;
            }
            else if(a[right]==i-1){
                right--;
                ans[n-i]=true;
                freq[i-1]--;
            }
            else{
                break;
            }
        }
        else{
            break;
        }
    }

    

    fo(i,n){
        cout<<ans[i];
    }cout<<nl;
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

