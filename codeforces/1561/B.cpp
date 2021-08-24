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
set<int> se;
void find(int serve,int br,int won,int a,int b){
    if(won>serve){
        return;
    }
    int oppo;
    // deb2(serve,won);
    int rem,ans;

    oppo=serve-won;
    rem=a-won;

    oppo+=max(0,br-rem);
    ans=serve-won+rem;
    // deb2(ans,rem);
    // deb2(oppo,b);
    if(oppo!=b){
        return;
    }
    se.insert(ans);
}
void solve(){
    int i,j;
    int a,b,n;
    cin>>a>>b;
    n=a+b;
    if(a<b){
        swap(a,b);
    }
    vi v;
    // deb2(a,b);
    int gap,t1,t2,temp,rem,br;
    br=(n+1)/2;
    gap=a-b;
    // fo(j,n+1){
    //     i=j;
    //     deb(i);
    //     t1=a;
    //     t2=b;

    //     temp=min({gap,i,br});

    //     t1-=temp;
    //     i-=temp;
        
    //     deb2(t1,t2);
    //     deb(i);

    //     if(i%2==0 && (t1+t2)%2==0){
    //         v.pb(j);
    //     }
    //     else if(i%2==1 && (t1+t2)%2==1){
    //         v.pb(j);
    //     }
    // }
    int serve;
    se.clear();
    for(i=0;i<=a;i++){
        if(n%2==0){
            find(n/2,n/2,i,a,b);
        }   
        else{
            find(n/2,n/2+1,i,a,b);
            find(n/2+1,n/2,i,a,b);
        }

    }
    cout<<se.size()<<nl;
    for(auto p: se){
        cout<<p<<" ";
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

