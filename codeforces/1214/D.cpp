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
ll store[N]={0},vis[N],dp[N],ok[N];

void reach(int i,int j,int n,int m,string s[]){
    int pos;
    pos=m*i + j;
    if(vis[pos]==1){
        return; 
    }
    vis[pos]=1;
    ok[pos]=true;
    // deb(pos);
    if(i<n-1 && s[i+1][j]=='.'){
        reach(i+1,j,n,m,s);
    }

    if(j<m-1 && s[i][j+1]=='.'){
        reach(i,j+1,n,m,s);
    }

}
void path1(int i,int j,int n,int m,string s[]){
    int pos;
    pos=m*i + j;
    if(vis[pos]==1){
        return ; 
    }
    // deb(pos);
    vis[pos]=1;
    store[pos]+=1;
    if(i==0 && j==0 ){
        return;
    }
    if(j>0 && s[i][j-1]=='.' && ok[pos-1]){
        path1(i,j-1,n,m,s);
    }
    else if(i>0 && s[i-1][j]=='.' && ok[pos-m]){
        path1(i-1,j,n,m,s);
    }
}
void path2(int i,int j,int n,int m,string s[]){
    int pos;
    pos=m*i + j;
    if(vis[pos]==1){
        return ;
    }
    // deb(pos);
    vis[pos]=1;
    store[pos]+=2;
    if(i==0 && j==0 ){
        return ;
    }
    if(i>0 && s[i-1][j]=='.' && ok[pos-m]){
        path2(i-1,j,n,m,s);
    }
    else if(j>0 && s[i][j-1]=='.' && ok[pos-1]){
        path2(i,j-1,n,m,s);
    }
   
}
void solve(){
    int i,j;
    int n,m;
    cin>>n>>m;
    string s[n];
    fo(i,n){
        cin>>s[i];
    }
    memset(vis,0,sizeof vis);
    memset(ok,false,sizeof ok);
    reach(0,0,n,m,s);

    memset(store,0,sizeof store);
    memset(vis,0,sizeof vis);
    path1(n-1,m-1,n,m,s);

    
    memset(vis,0,sizeof vis);
    path2(n-1,m-1,n,m,s);

    if(store[0]==0){
        cout<<"0\n";
        return;
    }
    fo2(i,1,n*m-2){
        if(store[i]==3){
            cout<<"1\n";
            return;
        }
    }
    cout<<"2\n";
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

