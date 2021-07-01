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
const int N=1e6;

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

vector<vector<int>> adj(N);
vector<int> vis(N),loop(N);
stack<int> st;
int P;
bool dfs(int node,int parent){
    vis[node]=1;
    // deb2(node,parent);
    st.push(node);
    for(auto child : adj[node]){
        // deb2(child,node);
        if(vis[child]==1 && parent!=child){
            // deb2(node,parent);
            P=child;
            // deb2(child,node);
            return true;
        }
        if(vis[child]==0){
            if(dfs(child,node)){
                // deb2(child,node);
                return true;
            }
        }
        
    }
    st.pop();
    return false;
}
int dfs1(int node){
    vis[node]=1;
    int curr=1;
    for(auto child : adj[node]){
        if(vis[child]==0 && loop[child]==0){
            curr+=dfs1(child);
        }
    }
    return curr;
}
void solve(){
    int i,j;
    int n;
    cin>>n;
    fo2(i,1,n){
        adj[i].clear();
        vis[i]=0;
        loop[i]=0;
    }
    fo(i,n){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    while(st.size()){
        st.pop();
    }
    bool del,flag=false;
    del=dfs(1,-1);
    // deb2(del,P);
    vi v1;
    while(st.size()){
        if(!flag){
            loop[st.top()]=1;
            v1.pb(st.top());
        }
        if(P==st.top()){
            flag=true;
        }
        // deb(st.top());
        st.pop();
    }
    ll count=0,ans=0;
    // fo(i,v1.size()){
    //     cout<<v1[i]<<" ";
    // }cout<<nl;
    fo2(i,1,n){
        vis[i]=0;
        // deb(loop[i]);
    }
    fo(i,v1.size()){
        count=dfs1(v1[i]);
        // deb(count);
        ans+=(count*(count-1)/2)+count*(n-count);
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

