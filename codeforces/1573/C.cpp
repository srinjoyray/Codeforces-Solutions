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
vl adj[N];
void solve(){
    int i,j;
    int n;
    cin>>n;
    int k[n+1],inp,ans[n+1]={0},vis[n+1]={0};
    map<int,set<int>> parent,child;
    set<int> se;
    fo2(i,1,n){
        parent[i].clear();
        child[i].clear();
    }
    fo2(i,1,n){
        cin>>k[i];
        fo(j,k[i]){
            cin>>inp;
            parent[i].insert(inp);
            child[inp].insert(i);
        }
    }

    fo2(i,1,n){
        if(parent[i].size()==0){
            se.insert(i);
        }
    }
    int val,temp;
    while(se.size()>0){
        val=*se.begin();
        se.erase(se.begin());
        vis[val]=1;
        for(auto p : child[val]){
            parent[p].erase(val);
            if(parent[p].size()==0){
                se.insert(p);
            }
            temp=ans[val];
            if(p<val){
                temp++;
            }
            ans[p]=max(ans[p],temp);
        }
    }
    fo2(i,1,n){
        if(vis[i]==0){
            cout<<"-1\n";
            return;
        }
    }
    cout<<*max_element(ans+1,ans+n+1)+1<<nl;;
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

