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
    int n;
    cin>>n;
    lli a[n],val[n]={0},sum=0,temp,init,ans=0,final,mn;
    fo(i,n){
        cin>>a[i];
    }
    fo2(i,1,n-2){
        if(a[i]>a[i-1] && a[i]>a[i+1]){
            val[i]=1;
            sum++;
        }
        else if(a[i]<a[i-1] && a[i]<a[i+1]){
            val[i]=-1;
            sum++;
        }
    }
    
    /*fo(i,n){
        cout<<val[i]<<" ";
    }cout<<nl;*/
    mn=sum;
    fo2(i,1,n-2){
        init=abs(val[i-1])+abs(val[i])+abs(val[i+1]);
        temp=a[i-1];
        final=0;
        if(i<n-2){
            if(a[i+1]>a[i+2] && a[i+1]>temp){
                final++;
            }
            if(a[i+1]<a[i+2] && a[i+1]<temp){
                final++;
            }
            
        }
        mn=min(mn,sum-(init-final));

        temp=a[i+1];
        final=0;
        if(i>=2){
            if(a[i-1]>a[i-2] && a[i-1]>temp){
                final++;
            }
            if(a[i-1]<a[i-2] && a[i-1]<temp){
                final++;
            }
            
        }
        mn=min(mn,sum-(init-final));
        
    }
    
    cout<<mn<<nl;

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

