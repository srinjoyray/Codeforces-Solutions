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

void solve()
{   int i,j;
    int n,m;
    cin>>n>>m;
    int a[n],b[n],c[m],last,pos=-1;
    map<int,vi> mapp;
    fo(i,n){
        cin>>a[i];
    }
    fo(i,n){
        cin>>b[i];
    }
    fo(i,m){
        cin>>c[i];
    }
    last=c[m-1];
    // deb(last);
    fo(i,n){
        // deb2(b[i],i);
        if(b[i]==last){
            // deb2(b[i],last);
            pos=i;
            break;
        }
    }
    fo(i,n){
        if(b[i]!=a[i] && b[i]==last){
            pos=i;
            break;
        }
    }
    if(pos==-1){
        cout<<"NO\n";
        return;
    }
    
    fo(i,n){
        if(b[i]!=a[i] && i!=pos){
            mapp[b[i]].pb(i);
        }
    }
    fo2(i,1,n){
        // deb2(i,mapp[i].size());
    }
    vi ans;
    fo(i,m-1){
        if(mapp[c[i]].size()==0){
            ans.pb(pos);
        }
        else{
            ans.pb(mapp[c[i]][0]);
            
            mapp[c[i]].erase(mapp[c[i]].begin());
            
            
        }
    }
    ans.pb(pos);
    fo2(i,1,n){
        if(mapp[i].size()>0){
            // deb(i);
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
    fo(i,ans.size()){
        cout<<ans[i]+1<<" ";
    }cout<<nl;

}

int main()
{   ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t=1;
    cin>>t;
    while(t--)
    {   //deb(t);
        solve();
    }
    return 0;
}

