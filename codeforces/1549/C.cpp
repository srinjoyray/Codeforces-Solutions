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
set<int> adj[N];
void solve(){
    int i,j;
    int n,m,count=0;
    cin>>n>>m;

    fo(i,m){
        int u,v;
        cin>>u>>v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    set<int> se;
    fo2(i,1,n){
        if(adj[i].size()>0 && *(adj[i].rbegin())>i){
            continue;
        }
        se.insert(i);
    }   
    int q;
    cin>>q;
    // deb(q);
    while(q--){
        int type;
        cin>>type;
        // deb(type);
        if(type==3){
            cout<<se.size()<<nl;
        }
        if(type==1){
            int u,v;
            cin>>u>>v;
            if(u>v){
                swap(u,v);
            }
            adj[u].insert(v);
            adj[v].insert(u);
            if(se.find(u)!=se.end()){
                se.erase(u);
            }
        }
        if(type==2){
            int u,v;
            cin>>u>>v;
            if(u>v){
                swap(u,v);
            }
            adj[u].erase(v);
            adj[v].erase(u);
            if(adj[u].size()>0 && *(adj[u].rbegin())>u){
                continue;
            }
            se.insert(u);
        }

    }
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    
}

