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
map<pii,int> mapp,vis;
int count1=0;
void rec(string s[],int i,int j,int n,int m,int k){
    if(vis[{i,j}]==1){
        return;
    }
    // deb2(count1,k);
    vis[{i,j}]=1;
    if(count1==k){
        return;
    }
    
    mapp[{i,j}]=1;
    count1++;
    
    if(i>0 && s[i-1][j]=='.'){
        rec(s,i-1,j,n,m,k);
    }
    if(i!=n-1 && s[i+1][j]=='.'){
        rec(s,i+1,j,n,m,k);
    }
    if(j>0 && s[i][j-1]=='.'){
        rec(s,i,j-1,n,m,k);
    }
    if(j!=m-1 && s[i][j+1]=='.'){
        rec(s,i,j+1,n,m,k);
    }

}
void solve(){
    int i,j;
    int n,m,k,temp;
    cin>>n>>m>>k;
    string s[n];
    fo(i,n){
        cin>>s[i];
        // deb(s[i]);
    }
    bool flag=false;
    mapp.clear();
    temp=0;
    fo(i,n){
        fo(j,m){
            if(s[i][j]=='.'){
                temp++;
            }
        }
    }
    // deb2(temp,k);
    k=temp-k;
    // deb(k);
    fo(i,n){
        fo(j,m){
            if(s[i][j]=='.'){
                rec(s,i,j,n,m,k);
                flag=true;
                break;
            }
        }
        if(flag){
            break;
        }
    }
    // deb(mapp.size());
    fo(i,n){
        fo(j,m){
            if(s[i][j]=='.' && mapp[{i,j}]==0){
                s[i][j]='X';
            }
        }
    }    
    
    fo(i,n){
        cout<<s[i]<<nl;    
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
    return 0;
}

