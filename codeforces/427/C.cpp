#include<bits/stdc++.h>
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define fo2(i,start,end) for(i=start;i<=end;i++)
#define rfo(i,n) for(i=n-1;i>=0;i--)
#define lli long long int
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
typedef pair<lli, lli>	pl;
typedef vector<int>		vi;
typedef vector<lli>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
map<int,int> vis;
map<int,vector<int>> mapp,trans;
vector<int> ans;
void dfs(int node,stack<int> &st){
    int i,j,child;
    vis[node]=1;
    
    fo(i,mapp[node].size()){
        child=mapp[node][i];
        if(vis[child]==0){
            dfs(child,st);
        }
    }
    st.push(node);
}
void dfs2(int node){
    vis[node]=true;
    ans.pb(node);
    int i,j,child;
    fo(i,trans[node].size()){
        child=trans[node][i];
        if(vis[child]==0){
            dfs2(child);
        }
    }
}
void solve(){
    int i,j;
    int n,m,u,v,node;
    cin>>n;
    lli a[n],count,val,temp,perm=1,sum=0,mx;
    fo(i,n){
        cin>>a[i];
    }
    mx=*max_element(a,a+n);
    mapp.clear();
    trans.clear();
    cin>>m;
    fo(i,m){
        cin>>u>>v;
        mapp[u].pb(v);
        trans[v].pb(u);
    }
    stack<int> st;
    vis.clear();

    fo2(i,1,n){
        if(vis[i]==0){
            dfs(i,st);
        }
    }
    vis.clear();
    while(!st.empty()){
        node=st.top();
        st.pop();
        if(vis[node]==0){
            ans.clear();
            dfs2(node);
            val=mx+1;
            count=0;
            fo(j,ans.size()){
                temp=a[ans[j]-1];
                if(temp<val){
                    val=temp;
                    count=1;
                }
                else if(temp==val){
                    count++;
                }
            }
            sum+=val;
            perm*=count;
            perm%=mod;
        }
    }
    /*fo2(i,1,n){
        if(vis[i]==1){
            continue;
        }
        ans.clear();
        dfs(i);
        val=mx+1;
        count=0;
        fo(j,ans.size()){
            temp=a[ans[j]-1];
            if(temp<val){
                val=temp;
                count=1;
            }
            else if(temp==val){
                count++;
            }
        }
        sum+=val;
        perm*=count;
        perm%=mod;
    }*/
    cout<<sum<<" "<<perm<<nl;
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
    return 0;
}

