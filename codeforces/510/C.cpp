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
map<int,vi> mapp;
map<int,int> vis;
string ans;
bool topo(){
    // deb(total);
    vi in(26,0);
    int i,j;
    fo(i,26){
        for(auto child:mapp[i]){
            in[child]++;
        }
    }
    queue<int> q;
    fo(i,26){
        if(in[i]==0){
            q.push(i);
        }
    }
    int count=0,temp;
    while(!q.empty()){
        temp=q.front();
        // deb(temp);
        q.pop();
        ans.pb(temp+'a');
        for(auto child:mapp[temp]){
            in[child]--;
            if(in[child]==0){
                q.push(child);
            }
        }
        count++;
    }
    if(count!=26){
        return false;
    }
    return true;
}
void solve(){
    int i,j;
    int n;
    cin>>n;
    string s[n];
    char ch;
    fo(i,n){
        cin>>s[i];
    }
    int sz,root=-1;
    fo2(i,0,n-2){
        sz=min(s[i].size(),s[i+1].size());
        fo(j,sz){
            if(s[i][j]!=s[i+1][j]){
                mapp[s[i][j]-'a'].pb(s[i+1][j]-'a');
                vis[s[i][j]-'a']++;
                vis[s[i+1][j]-'a']++;
                if(root==-1){
                    root=s[i][j]-'a';
                }
                break;
            }
            if(j==sz-1){
                if(s[i].size()>sz){
                    cout<<"Impossible\n";
                    return;
                }
            }
        }
    }
    if(root==-1){
        fo(j,26){
            cout<<char('a'+j);
        }
        return;
    }
    
    if(topo()==false){
        cout<<"Impossible\n";
    }
    else{
        fo(i,26){
            ch='a'+i;
            fo(j,ans.size()){
                if(ans[j]==ch){
                    break;
                }
                else if(j==ans.size()-1){
                    ans.pb(ch);
                }
            }
        }
        cout<<ans<<nl;
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

