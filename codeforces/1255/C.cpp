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
    int i,j;
    int n,a,b,c;
    cin>>n;
    map<lli,vpl>m;
    map<lli,lli> freq,vis,temp;
    fo(i,n-2){
        cin>>a>>b>>c;
        m[a].pb({b,c});
        m[b].pb({a,c});
        m[c].pb({a,b});
        freq[a]++; freq[b]++; freq[c]++;
    }
    lli start=-1,end,mx;
    vl v;
    fo2(i,1,n){
        if(freq[i]==1 && start==-1){
            start=i;
        }
        else if(freq[i]==1){
            end=i;
        }
    }
    while(v.size()<n-2){
        // deb(start);
        v.pb(start);
        vis[start]=1;
        temp.clear();
        mx=0;
        for(auto x:m[start]){
            a=x.F;
            b=x.S;
            // deb2(a,b);
            if(vis[a]==0){
                freq[a]--;
                temp[a]++;
            }
            if(vis[b]==0){
                freq[b]--;
                temp[b]++;
            }
            // deb2(freq[a],temp[a]);
            // deb2(freq[b],temp[b]);
            if(temp[a]>mx){
                mx=temp[a];
                start=a;
            }
            else if(temp[a]==mx && freq[a]==1){
                mx=temp[a];
                start=a;
            }
            // deb2(start,mx);
            if(temp[b]>mx){
                mx=temp[b];
                start=b;
            }
            else if(temp[b]==mx && freq[b]==1){
                mx=temp[b];
                start=b;
            }
            // deb(start);
        }
    }
    for(auto x:m[end]){
        if(vis[x.F]==0){
            v.pb(x.F);
            break;
        }
        if(vis[x.S]==0){
            v.pb(x.S);
            break;
        }
    }
    v.pb(end);
    fo(i,v.size()){
        cout<<v[i]<<" ";
    }cout<<nl;
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

