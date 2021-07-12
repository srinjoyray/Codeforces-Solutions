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
map<int,vi> adj;
map<pii,int> wt;
map<int,int> leaves,vis;
void dfs(int node){
    vis[node]=1;
    int count=0;
    for(auto child : adj[node]){
        if(vis[child]==0){
            dfs(child);
            count+=leaves[child];
        }
    }
    if(adj[node].size()==1 && node!=1){
        count=1;
    }
    leaves[node]=count;
}
void solve(){
    int i,j;
    ll n;
    ll s;
    cin>>n>>s;
    ll u,v,w;
    ll temp,rem,count;
    fo2(i,1,n){
        vis[i]=0;
        adj[i].clear();
        leaves[i]=0;
    }
    fo(i,n-1){
        
        cin>>u>>v>>w;
        adj[u].pb(v);
        adj[v].pb(u);
        wt[{u,v}]=w;
        wt[{v,u}]=w;
    }

    dfs(1);
    // fo2(i,1,n){
    //     deb2(i,leaves[i]);
    // }
    multiset<pl> se;
    fo2(i,1,n){
        for(auto child : adj[i]){
            if(child>i){
                w=wt[{child,i}];
                rem=(w-w/2);
                count=min(leaves[i],leaves[child]);
                se.insert({(rem*count),w});
            }
        }
    }
    ll ans=0,sum=0;
    // for(auto x : se){
    //     cout<<x.F<<" "<<x.S<<nl;
    // }
    for(auto x : se){
        w=x.S;
        rem=w-w/2;
        count=x.F/rem;
        sum+=count*w;
    }
    
    // deb(sum);
    while(sum>s){
        auto x=*se.rbegin();
        se.erase(se.find(x));
        // deb2(x.F,x.S);

        w=x.S;
        rem=w-w/2;
        count=x.F/rem;
        sum-=x.F;

        w/=2;
        rem=w-w/2;
        se.insert({rem*count,w});
        ans++;
        // deb2(rem*count,w);
        // deb(sum);
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
    // int i;
    // fo(i,t){cout<<"Case #"<<i+1<<": ";solve();}
}

