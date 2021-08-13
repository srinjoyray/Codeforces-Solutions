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
ll power(ll a,ll n){
    ll res=1;
    while(n){
        if(n%2){
            res=(res*a)%mod;
        }
        a=(a*a)%mod;
        n/=2;
    }
    return res;
}
vector<map<ll,ll>> array_freq(N);
map<ll,multiset<ll>> prime_freq;
vpii find(ll n){
    vpii v;
    // deb(n);
    int val,count,temp;
    while(spf[n]!=n){
        // deb2(spf[n],n);
        val=spf[n];
        count=0;
        while(n%val==0){
            n/=val;
            count++;
        }
        v.pb({val,count});
    }
    if(n>1){
        v.pb({n,1});
    }
    int i;
    // fo(i,v.size()){
    //     cout<<v[i].F<<" "<<v[i].S<<nl;
    // }
    return v;
}
void solve(){
    int i,j;
    int n,q;
    cin>>n>>q;
    ll a[n],ans,temp;
    fo(i,n){
        cin>>a[i];
    }
    ans=a[0];
    fo(i,n){
        vpii primes;
        primes=find(a[i]);
        fo(j,primes.size()){
            prime_freq[primes[j].F].insert(primes[j].S);
            array_freq[i][primes[j].F]=primes[j].S;
        }
        ans=__gcd(ans,a[i]);
    }
    // deb(ans);
    while(q--){
        ll idx,val;
        cin>>idx>>val;
        idx--;
        vpii primes;
        primes=find(val);
        // deb(val);
        fo(j,primes.size()){
            // deb2(primes[j].F,primes[j].S);
            ll prev,curr,prev_ans=0,curr_ans=0;
            if(prime_freq[primes[j].F].size()==n){
                prev_ans=*prime_freq[primes[j].F].begin();
            }   
            prev=array_freq[idx][primes[j].F];
            curr=primes[j].S+prev;
            array_freq[idx][primes[j].F]=curr;
            prime_freq[primes[j].F].insert(curr);
            if(prev>0){
                prime_freq[primes[j].F].erase(prime_freq[primes[j].F].find(prev));
            }
            if(prime_freq[primes[j].F].size()==n){
                curr_ans=*prime_freq[primes[j].F].begin();
            }   
            // deb2(prev,curr);
            // deb2(prev_ans,curr_ans);

            temp=power(primes[j].F,curr_ans-prev_ans);
            ans=(ans*temp)%mod;
             
        }
        cout<<ans<<nl;   
    }
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

