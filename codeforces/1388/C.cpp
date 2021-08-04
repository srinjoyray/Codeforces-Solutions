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
bool flag;
vi adj[N];
int p[N],h[N];
pii dfs(int node,int parent){
    
    pii temp,sum={0,0};
    for(int child : adj[node]){
        if(child!=parent && flag){
            temp=dfs(child,node);
            sum.F+=temp.F;
            sum.S+=temp.S;
            p[node]+=p[child];
        }
    }
    // deb2(h[node],p[node]);
    // deb2(sum.F,sum.S);
    int curr,diff,pos,neg,total;
    
    curr=sum.F+sum.S;
    total=p[node];
    pos=abs(total-abs(h[node]))/2;
    neg=abs(total-abs(h[node]))/2;
    if(h[node]>=0){
        pos+=h[node];
    }
    else{
        neg+=abs(h[node]);
    }
    // deb2(pos,neg);
    // deb(total);
    // deb2(sum.F,sum.S);

    if(sum.F>pos || pos+neg!=total){
        // deb2(node,parent);
        flag=false;
        return {-1,-1};
    }

    sum.F=pos;
    sum.S=neg;

    // deb(node);
    // deb2(sum.F,sum.S);
    return sum;
}
void solve(){
    int i,j;
    int n,m;
    cin>>n>>m;
    
    fo2(i,1,n){
        cin>>p[i];
    }
    fo2(i,1,n){
        cin>>h[i];
    }
    fo2(i,1,n){
        adj[i].clear();
    }
    fo(i,n-1){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    flag=true;
    dfs(1,-1);

    if(flag){
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
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    
}

  