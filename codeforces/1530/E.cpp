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
    string s,ans;
    cin>>s;
    int n,freq[26]={0},mx=0,val,count=0,imp,temp;
    n=s.size();
    set<int> se;
    
    fo(i,n){
        val=s[i]-'a';
        se.insert(val);
        if(freq[val]==0){
            count++;
        }
        freq[val]++;
        mx=max(mx,freq[val]);
    }

    if(mx==1 || count==1){
        fo(i,26){
            fo(j,freq[i]){
                ans.pb('a'+i);
            }
        }
        cout<<ans<<nl;
        return;
    }
    fo(i,26){
        if(freq[i]==1){
            ans.pb(i+'a');
            freq[i]--;
            fo(j,26){
                while(freq[j]--){
                    ans.pb('a'+j);
                }
            }
            cout<<ans<<nl;
            return;
        }

    }
    imp=*se.begin();


    if(freq[imp]> n/2 + 1){
        se.erase(imp);
        ans.pb(imp+'a');
        freq[imp]--;
        if(se.size()==1){
            val=*se.begin();
            fo(j,freq[val]){
                ans.pb('a'+val);
            }

            fo(j,freq[imp]){
                ans.pb('a'+imp);
            }
            cout<<ans<<nl;
            return;
        }
        val=*se.begin();
        ans.pb(val+'a');
        freq[val]--;    
        fo(i,freq[imp]){
            ans.pb(imp+'a');
        }
        val=*(++se.begin());
        ans.pb(val+'a');
        freq[val]--;

        while(se.size()>0){
            val=*se.begin();
            if(freq[val]==0){
                se.erase(val);
                continue;
            }
            ans.pb(val+'a');
            freq[val]--;
        }

        cout<<ans<<nl;

        return;
    }

    se.erase(imp);
    ans.pb(imp+'a');
    freq[imp]--;
    while(freq[imp]>0){
        ans.pb(imp+'a');
        freq[imp]--;
        if(se.size()>0){
            temp=*se.begin();
            ans.pb(temp+'a');
            freq[temp]--;
            if(freq[temp]==0){
                se.erase(temp);
            }
        }    
    }
    while(se.size()>0){
        temp=*se.begin();
        ans.pb(temp+'a');
        freq[temp]--;
        if(freq[temp]==0){
            se.erase(temp);
        }
    }
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
    
}

