#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fo(i,n) for(i=0;i<n;i++)
#define fo2(i,start,end) for(i=start;i<=end;i++)
#define rfo(i,n) for(i=n-1;i>=0;i--)
#define deb(x) cout<<#x<<"="<<x<<endl
#define deb2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
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
map<pii,int> vis;
void track(int i,int j,string s[],int n,int m){
    if(vis[{i,j}]==1){
        return;
    }
    // deb2(i,j);
    vis[{i,j}]=1;
    if(j<m-1 && s[i][j+1]=='.'){
        track(i,j+1,s,n,m);
    }
    if(i<n-1 && s[i+1][j]=='.'){
        track(i+1,j,s,n,m);
    }
}
void solve(){
    int i,j;
    int n,m;
    cin>>n>>m;
    // deb2(n,m);
    string s[n];
    vis.clear();
    fo(i,n){
        cin>>s[i];
    }
    fo(j,m){
        if(s[0][j]=='.'){
            track(0,j,s,n,m);
        }
    }
    fo(i,n){
        if(s[0][j]=='.'){
            track(i,0,s,n,m);
        }
    }
    int a[n][m],col[m]={0},pref[m+1]={0};
    // fo(i,n){
    //     fo(j,m){
    //         if(vis[{i,j}]==0 && s[i][j]=='.'){
    //             col[j]=1;
    //         }
    //     }
    // }
   
    for(j=m-1;j>0;j--){
        for(i=0;i<n-1;i++){
            if(s[i][j]=='X' && s[i+1][j-1]=='X'){
                col[j]=1;
            }
        }
    }
    // fo(i,m){
    //     cout<<col[i]<<" ";
    // }cout<<nl;
    fo2(i,1,m){
        pref[i]=pref[i-1]+col[i-1];
    }
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        if(pref[r]==pref[l]){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
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

