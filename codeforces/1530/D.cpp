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

/*bool prime[N + 1];
void sieveOfEratosthenes()
{
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= N; p++)
    {
        if (prime[p] == true){
            for (int i = p * p; i <= N; i += p)
                prime[i] = false;
        }
    }
    prime[0]=false; prime[1]=false;
}*/

/*int spf[N];
void sieve()
{
    spf[1] = 1;
    for (int i=2; i<N; i++)
        spf[i] = i;

    for (int i=4; i<N; i+=2)
        spf[i] = 2;
 
    for (int i=3; i*i<N; i++){
        if (spf[i] == i){
            for (int j=i*i; j<N; j+=i)
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}*/

/*string to_binary(int n){
    int binaryNum[32]={0};
    string s;
    int i=0,j;
    while(n>0){
        binaryNum[i] = n % 2;
        n=n/2;
        i++;
    }
    fo(j,32){
        s.pb(binaryNum[j]+'0');
    }
    reverse(all(s));
    return s;
}*/

/*ll power(ll a,ll n){
    ll res=1;
    while(n){
        if(n%2){
            res=(res*a)%mod;
        }
        a=(a*a)%mod;
        n/=2;
    }
    return res;
}*/

void solve(){
    int i,j;
    int n;
    cin>>n;
    int a[n+100],k,b[n+100]={0},val;
    set<int> se,free,rem;
    map<int,vi> freq;
    fo2(i,1,n){
        cin>>a[i];
        se.insert(a[i]);
        freq[a[i]].pb(i);
    }
    k=se.size();
    set<pii> sp;

    fo2(i,1,n){
        if(freq[i].size()>0){
            sp.insert({freq[i].size(),i});
        }
        else{
            rem.insert(i);
        }
    }
    
    for(auto x : sp){
        val=x.S;
        free.insert(val);
        for(auto y : freq[val]){
            if(free.find(y)==free.end()){
                b[y]=val;
                se.erase(val);
                break;
            }
        }
        if(se.find(val)!=se.end()){
            b[freq[val][0]]=val;
        }
        
    }
    set<int> pos,imp;
    fo2(i,1,n){
        if(b[i]==0){
            if(rem.find(i)!=rem.end()){
                imp.insert(i);
            }
            else{
                pos.insert(i);
            }
        }
    }

    for(auto x: imp){
        // deb(x);
        for(auto y : rem){
            // deb(y);
            if(x!=y){
                b[x]=y;
                rem.erase(y);
                break;
            }
        }
    }
    for(auto x : pos){
        b[x]=*rem.begin();
        rem.erase(rem.begin());
    }


    cout<<k<<nl;
    fo2(i,1,n){
        cout<<b[i]<<" ";
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

