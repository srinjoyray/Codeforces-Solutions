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
void solve(){
    int i,j;
    int n,input;
    map<int,set<int>> adj;
    map<int,int> vis;
    cin>>n;
    fo(i,n-1){
        int x,y;
        cin>>x>>y;
        adj[x].insert(y);
        adj[y].insert(x);
    }
    while(true){
        int node1=-1,node2=-1,input;
        fo2(i,1,n){
            if(adj[i].size()<=1 && vis[i]==0){
                if(node1==-1){
                    node1=i;
                }
                else{
                    node2=i;
                    break;
                }
            }
        }
        if(node2==-1){
            cout<<"! "<<node1<<endl;
            return;
        }

        cout<<"? "<<node1<<" "<<node2<<endl;
        cin>>input;
        
        if(input==node1){
            cout<<"! "<<node1<<endl;
            return;
        }
        if(input==node2){
            cout<<"! "<<node2<<endl;
            return;
        }

        adj[node1].clear();
        adj[node2].clear();
        vis[node1]=1;
        vis[node2]=1;

        fo2(i,1,n){
            adj[i].erase(node1);
            adj[i].erase(node2);
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

