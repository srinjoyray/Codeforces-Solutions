#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fo(i,n) for(i=0;i<n;i++)
#define fo2(i,start,end) for(i=start;i<=end;i++)
#define rfo(i,n) for(i=n-1;i>=0;i--)
#define deb(x) cerr<<#x<<"="<<x<<endl
#define deb2(x,y) cerr<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
#define ll long long
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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

const int N=1e6+10;

void solve(){
    int i,j;
    int n;
    cin>>n;
    vpl p(n),ans(n);
    set<pl> se;
    map<pl,ll> mapp,vis;
    fo(i,n){
        cin>>p[i].F>>p[i].S;
        se.insert(p[i]);
        mapp[p[i]]=i;
    }
    queue<pl> q;

    fo(i,n){
        ll x,y;
        x=p[i].F , y=p[i].S;
        if(se.find({x-1,y})==se.end()){
            ans[i]={x-1,y};
            q.push({i,i});
            vis[{x,y}] = 1;
        }
        else if(se.find({x+1,y}) == se.end()){
            ans[i]={x+1,y};
            q.push({i,i});
            vis[{x,y}] = 1;
        }
        else if(se.find({x,y-1}) == se.end()){
            ans[i] = {x,y-1};
            q.push({i,i});
            vis[{x,y}] = 1;
        }
        else if(se.find({x,y+1}) == se.end()){
            ans[i] = {x,y+1};
            q.push({i,i});
            vis[{x,y}] = 1;
        }
    }

    while(!q.empty()){
        ll idx,x,y,index;
        pl t = q.front();
        q.pop();
        idx = t.F;
        x = p[idx].F;
        y = p[idx].S;
        if(se.find({x-1,y}) != se.end() && vis[{x-1,y}] == 0){
            index = mapp[{x-1,y}];
            ans[index] = ans[t.S];
            vis[{x-1,y}] = 1;
            q.push({index,t.S});
        }
        if(se.find({x+1,y}) != se.end() && vis[{x+1,y}] == 0){
            index = mapp[{x+1,y}];
            ans[index] = ans[t.S];
            vis[{x+1,y}] = 1;
            q.push({index,t.S});
        }
        if(se.find({x,y+1}) != se.end() && vis[{x,y+1}] == 0){
            index = mapp[{x,y+1}];
            ans[index] = ans[t.S];
            vis[{x,y+1}] = 1;
            q.push({index,t.S});
        }
        if(se.find({x,y-1}) != se.end() && vis[{x,y-1}] == 0){
            index = mapp[{x,y-1}];
            ans[index] = ans[t.S];
            vis[{x,y-1}] = 1;
            q.push({index,t.S});
        }
    }

    fo(i,n){
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

