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
const int maxN = 3e5+10;
const int logN = 20;
int gold[maxN],cost[maxN],parent[maxN][logN];
void solve(){
    int i,j;
    
    int q;
    cin>>q;  
    cin>>gold[0]>>cost[0];
    memset(parent,-1,sizeof(parent));
    
    fo2(i,1,q){
        int type;
        cin>>type;
        // deb(type);
        if(type==1){
            int p,a,c;
            cin>>p>>a>>c;
            
            parent[i][0]=p;
            cost[i]=c;
            gold[i]=a;
           
            for(j=1;j<logN;j++){
                int par=parent[i][j-1];
                if(par!=-1){
                    parent[i][j]=parent[par][j-1];
                }
            }
            
        }
        else{
            int v,w,curr_node;
            cin>>v>>w;
            ll curr_gold=0,curr_cost=0;
            while(w){
                curr_node=v;
                for(j=logN-1;j>=0;j--){
                    if(parent[curr_node][j]!=-1){
                        int ancestor=parent[curr_node][j];
                        if(gold[ancestor]>0){
                            curr_node=ancestor;
                        }
                    }
                }
                ll req=min(w,gold[curr_node]);
                w-=req;
                gold[curr_node]-=req;
                curr_gold+=req;
                curr_cost+=req*cost[curr_node];
                if(curr_node==v){
                    break;
                }
            }

            cout<<curr_gold<<" "<<curr_cost<<endl;
            fflush(stdout);
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

