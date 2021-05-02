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
    int n,l,r;
    cin>>n>>l>>r;
    int c[n];
    fo(i,n){
        cin>>c[i];
    }
    map<lli,lli> left,right;
    lli ans=0,temp,temp1,temp2,l1=0,r1=0;
    fo(i,l){
        left[c[i]]++;
    }
    fo2(i,l,n-1){
        right[c[i]]++;
    }
    fo2(i,1,n){
        temp=min(left[i],right[i]);
        left[i]-=temp;
        right[i]-=temp;
        temp=left[i]/2;
        l1+=temp*2;
        temp=right[i]/2;
        r1+=temp*2;
    }
    temp1=0;
    temp2=0;
    fo2(i,1,n){
        if(left[i]>0){
            temp1+=left[i];
        }
        if(right[i]>0){
            temp2+=right[i];
        }
    }
    // deb2(temp1,temp2);
    temp=min(temp1,temp2);
    ans+=temp;
    temp1-=temp;
    temp2-=temp;
    
    temp=min(temp1,l1);
    if(temp%2==1){
        temp--;
    }
    ans+=temp/2;
    temp1-=temp;
    ans+=temp1;
    
    temp=min(temp2,r1);
    if(temp%2==1){
        temp--;
    }
    ans+=temp/2;
    temp2-=temp;
    ans+=temp2;


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
    return 0;
}

