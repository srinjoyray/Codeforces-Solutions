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
map<int,vector<int>> mapp;
void solve(){
    int i,j;
    int n,x,u,v,temp,dist,count=0;
    bool flag;
    mapp.clear();
    cin>>n>>x;
    fo(i,n-1){
        cin>>u>>v;
        mapp[u].pb(v);
        mapp[v].pb(u);
    }
    if(mapp[x].size()==1 || n==1){
        cout<<"Ayush\n";
        return;
    }
    while(true){
        flag=false;
        fo2(i,1,n){
            if(mapp[i].size()==1){
                temp=mapp[i][0];
                if(temp==x && mapp[temp].size()<=2){
                    continue;
                }
                mapp[i].clear();
                fo(j,mapp[temp].size()){
                    if(mapp[temp][j]==i){
                        mapp[temp].erase(mapp[temp].begin()+j);
                        flag=true;
                        break;
                    }
                }
                count++;
            }
        }
        if(flag==false){
            break;
        }
    }
    // deb(count);
    if(count%2==0){
        cout<<"Ashish\n";
    }
    else{
        cout<<"Ayush\n";
    }
    /*fo(i,mapp[x].size()){
        temp=mapp[x][i];
        dist=func(temp);

    }*/
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
    return 0;
}

