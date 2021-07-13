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
const int N=1e7+10;

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

int spf[N];
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
}
pii find(int val){
    vpii v;
    int i,j,i1,j1,temp,copy,count,t1,t2;
    copy=val;
    if(spf[val]!=val){
        temp=spf[val];
        while(val%temp==0){
            val/=temp;
        }
        if(val!=1){
            return {temp,val};
        }
    }
    /*while(spf[val]!=val){
        // deb(val);
        temp=spf[val];
        count=0;
        
        while(val%temp==0){
            val/=temp;
            count++;
        }
        // deb2(temp,count);
        v.pb({temp,count});
    }
    // deb(val);
    if(val!=1){
        v.pb({val,1});
    }
    val=copy;
    fo(i,v.size()){
        fo2(j,i+1,v.size()-1){
            // deb2(v[i].F,v[j].F);
            fo2(i1,1,v[i].S){
                fo2(j1,1,v[j].S){
                    t1=pow(v[i].F,i1);
                    t2=pow(v[j].F,j1);
                    // deb2(t1,t2);
                    temp=t1+t2;
                    if(__gcd(temp,val)==1){
                        return {t1,t2};
                    }
                }
            }
        }
    }*/
    
    return {-1,-1};
}

void solve(){
    int i,j;
    int n;
    cin>>n;
    int a[n];
    fo(i,n){
        cin>>a[i];
    }
    vi v1(n),v2(n);
    fo(i,n){
        pii p=find(a[i]);
        v1[i]=p.F;
        v2[i]=p.S;
    }

    fo(i,n){
        cout<<v1[i]<<" ";
    }cout<<nl;
    
    fo(i,n){
        cout<<v2[i]<<" ";
    }cout<<nl;

}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t=1;
    // cin>>t;
    sieve();
    while(t--){
        solve();
    }
    
}

