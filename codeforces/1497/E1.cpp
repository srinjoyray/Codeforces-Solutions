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

#define MAXN   10000001
 
int spf[MAXN];
void sieve()
{
    spf[1] = 1;
    for (int i=2; i<MAXN; i++)
        spf[i] = i;
 
    for (int i=4; i<MAXN; i+=2)
        spf[i] = 2;
 
    for (int i=3; i*i<MAXN; i++)
    {
        
        if (spf[i] == i)
        {
            
            for (int j=i*i; j<MAXN; j+=i)
 
                
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}
lli change(lli n){  
    // deb(n);
    vi v;
    lli store=n;
    while(spf[n]!=n){
        v.pb(spf[n]);
        n=n/spf[n];
    }
    v.pb(n);
    sort(all(v));
    // deb(v.size());
    lli temp=1;
    for(int i=0;i<v.size()-1;i++){
        if(v[i]==v[i+1]){
            temp*=v[i]*v[i];
            i++;
        }
    }
    // deb(temp);
    return store/temp; 
}
void solve(){
    int i,j;
    int n,k;
    cin>>n>>k;
    lli a[n];
    fo(i,n){
        cin>>a[i];
    }
    fo(i,n){
        a[i]=change(a[i]);
        // deb(a[i]);
    }
    /*fo(i,n){
        cout<<a[i]<<" ";
    }cout<<nl;*/
    map<lli,lli> m;
    lli count=1;
    fo(i,n){
        if(m[a[i]]==1){
            count++;
            m.clear();
        }
        m[a[i]]++;
        // deb2(i,count);
    }
    cout<<count<<nl;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    lli i,t=1,j,temp;
    cin>>t;
    
    sieve();

    while(t--){
        solve();
    }
    return 0;
}

