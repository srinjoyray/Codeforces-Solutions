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
    lli i,j;
    lli n,temp,upto,dig=0,val=0,rem;
    cin>>n;
    dig=n;
    upto=n/7;
    // deb(upto);
    for(i=0;i<=upto;i++){
        rem=n-7*i;
        // deb(rem);
        if(rem%4==0){
            temp=i+rem/4;
            if(temp<dig){
                dig=temp;
                val=rem/4;
            }
            else if(temp==dig){
                val=max(val,rem/4);
            }
        }
    }
    if(dig==n){
        cout<<"-1\n";
        return;
    }
    fo(i,val){
        cout<<"4";
    }
    fo(i,dig-val){
        cout<<"7";
    }
    cout<<nl;
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

