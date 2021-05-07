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
void solve(){
    int i,j,k;
    string s;
    cin>>s;
    map<int,vi> m;
    vi v[26];
    int n,pos=-1,vis[26]={0};
    n=s.size();
    if(n==1){
        cout<<"YES\n";
        fo(j,26){
            cout<<char(j+'a');
        }cout<<nl;
        return;
    }


    fo(i,n){
        if(i>0){
            m[s[i]-'a'].pb(s[i-1]-'a');
        }
        if(i<n-1){
            m[s[i]-'a'].pb(s[i+1]-'a');
        }
    }
    fo(i,26){
        sort(all(m[i]));
    }
    fo(i,26){
        fo(j,m[i].size()){
            k=j+1l;
            while(k<m[i].size() && m[i][j]==m[i][k]){
                k++;
            }
            v[i].pb(m[i][j]);
            j=k-1;
        }
    }
    fo(i,26){
        if(v[i].size()>2){
            cout<<"NO\n";
            return;
        }
        if(v[i].size()==1){
            pos=i;
        }
    }
    if(pos==-1){
        cout<<"NO\n";
        return;
    }
    vi v1;
    string ans;
    v1.pb(pos);
    vis[pos]=1;
    pos=v[pos][0];
    while(true){
        v1.pb(pos);
        vis[pos]=1;
        if(v[pos].size()==1){
            break;
        }
        if(vis[v[pos][0]]==0){
            pos=v[pos][0];
        }
        else{
            pos=v[pos][1];
        }
    }
    fo(i,26){
        if(vis[i]==0){
            v1.pb(i);
        }
    }
    /*fo(i,26){
        cout<<v1[i]<<" ";
    }cout<<nl;*/

    fo(i,v1.size()){
        ans.pb(v1[i]+'a');
    }
    cout<<"YES\n";
    cout<<ans<<nl;
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

