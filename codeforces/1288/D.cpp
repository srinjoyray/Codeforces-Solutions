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
pii p;
ll a[N][10];
int n,m;
map<int,int> mapp;

bool check(int val){
    int i,j,curr,total,sum,temp;
    vi s(n);
    mapp.clear();
    
    // deb(val);
    fo(i,n){
        curr=1;
        sum=0;
        fo(j,m){
            if(a[i][j]>=val){
                sum+=curr;
            }
            curr*=2;
        }
        s[i]=sum;
        mapp[sum]=i+1;
        // deb2(i,sum);          
    }
    
    
    total=pow(2,m)-1;
    
    for(i=0;i<=total;i++){
        for(j=0;j<=total;j++){
            if(mapp[i]>0 && mapp[j]>0 && (i|j)==total){
                p={mapp[i],mapp[j]};
                return true;
            }
        }
    }

    return false;
}
void solve(){
    int i,j;
    cin>>n>>m;
    fo(i,n){
        fo(j,m){
            // a[i][j]=1;
            cin>>a[i][j];
        }
    }
    ll mn=0,mx=1e9+10,ans=0,mid;
    while(mn<=mx){
        mid=(mn+mx)/2;
        // deb(mid);
        if(check(mid)){
            ans=mid;
            mn=mid+1;
        }
        else{
            mx=mid-1;
        }
        // deb2(p.F,p.S);
    }
    // cout<<ans<<nl;
    cout<<p.F<<" "<<p.S<<nl;
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

