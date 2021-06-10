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
#define N   100000
bool prime[N+1];
vi v;
int func(int n){
    // deb(n);
    int i,count,ans=0;
    if(n==1){
        return 0;
    }
    int temp=n;
    fo(i,v.size()){
        count=0;
        
        while(n%v[i]==0){
            n/=v[i];
            count++;
        }
       
        ans+=count;
    }
    if(n>1){
        ans++;
    }
    return ans;
}
void solve(){
    int i,j;
    ll a,b,k,total;
    cin>>a>>b>>k;

    if(k==1){
        if((a%b==0 || b%a==0)&& a!=b){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
        return ;
    }
    total=func(a)+func(b);
    
    // deb(total);
    if(total>=k){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t=1,i;
    cin>>t;
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= N; p++)
    {
        // If prime[p] is not changed,
        // then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples
            // of p greater than or
            // equal to the square of it
            // numbers which are multiple
            // of p and are less than p^2
            // are already been marked.
            for (i = p * p; i <= N; i += p)
                prime[i] = false;
        }
    }
    fo(i,N){
        if(prime[i] && i>=2){
            v.pb(i);
        }
    }
    // deb(v.size());
    // deb2(v[0],v[1]);
    while(t--){
        solve();
    }
}

