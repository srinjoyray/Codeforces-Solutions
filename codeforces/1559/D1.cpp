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
vi adj1[N],adj2[N],vis1(N),vis2(N),val1(N),val2(N);
map<int,vi> mp1,mp2;
void dfs1(int node,int curr){
    vis1[node]=1;
    val1[node]=curr;
    mp1[curr].pb(node);
    for(int child : adj1[node]){
        if(vis1[child]==0){
            dfs1(child,curr);
        }
    }
}
void dfs2(int node,int curr){
    vis2[node]=1;
    val2[node]=curr;
    mp2[curr].pb(node);
    for(int child : adj2[node]){
        if(vis2[child]==0){
            dfs2(child,curr);
        }
    }
}
void solve(){
    int i,j;
    int n,m1,m2;
    cin>>n>>m1>>m2;

    fo(i,m1){
        int u,v;
        cin>>u>>v;
        // deb2(u,v);
        adj1[u].pb(v);
        adj1[v].pb(u);
    }
    fo(i,m2){
        int u,v;
        cin>>u>>v;
        // deb2(u,v);
        adj2[u].pb(v);
        adj2[v].pb(u);
    }
    int curr=1;
    fo2(i,1,n){
        if(vis1[i]==0){
            dfs1(i,curr);
            curr++;
        }
    }
    curr=1;
    fo2(i,1,n){
        if(vis2[i]==0){
            dfs2(i,curr);
            curr++;
        }
    }
    vpii ans;
    set<pii>se;
    fo2(i,1,n){
        fo2(j,i+1,n){
            if(val1[i]!=val1[j] && val2[i]!=val2[j]){
                se.insert({i,j});
            }
        }
    }
    map<int,int> mp1,mp2;
    for(auto p : se){
        pii t1,t2;
        i=p.F;
        j=p.S;
        t1={val1[i],val1[j]};
        t2={val2[i],val2[j]};
        if(mp1[t1.F]>0 && mp1[t1.S]>0){
            continue;
        }
        if(mp2[t2.F]>0 && mp2[t2.S]>0){
            continue;
        }
        // deb2(i,j);
        // deb2(t1.F,t1.S);
        // deb2(t2.F,t2.S);
        ans.pb({i,j});
        mp1[t1.F]++; mp1[t1.S]++;
        mp2[t2.F]++; mp2[t2.S]++;
    }


    // map<pii,int> mapp1,mapp2;
    
    // fo2(i,1,n){
    //     // deb2(i,val1[i]);
    //     if(val1[i]!=1){
    //         continue;
    //     }
    //     fo2(j,1,n){
    //         if(i==j){
    //             continue;
    //         }
    //         if(val1[i]!=val1[j] && val2[i]!=val2[j] ){
    //             if(mapp1[{val1[i],val1[j]}]==0 && mapp2[{val1[i],val2[j]}]==0){
    //                 ans.pb({i,j});
    //                 mapp1[{val1[i],val1[j]}]++;
    //                 mapp2[{val1[i],val2[j]}]++;
    //                 // deb2(i,j);
    //                 // deb2(val1[i],val2[j]);
    //             }
    //         }
    //     }
        
    // }
    

    cout<<ans.size()<<nl;
    fo(i,ans.size()){
        cout<<ans[i].F<<" "<<ans[i].S<<nl;
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

