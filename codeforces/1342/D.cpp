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
void solve(){
    int i,j;
    int n,k;
    cin>>n>>k;
    int m[n],c[k],temp;
    set<int> se;
    fo(i,n){
        cin>>m[i];
        se.insert(m[i]);
    }
    fo(i,k){
        cin>>c[i];
    }
    sort(m,m+n);
    map<int,int> mapp;
    fo(i,n){
        if(mapp[m[i]]==0){
            mapp[m[i]]=n-i;
        }
    }
    
    int mx=1,val;
    for(auto itr=se.begin();itr!=se.end();itr++){
        i=*itr;
        temp=(mapp[i]+c[i-1]-1)/c[i-1];
        // deb2(i,temp);
        // deb(mapp[i]);
        mx=max(mx,temp);
    }
    cout<<mx<<nl;
    vi v[mx];
    j=0;
    sort(m,m+n,greater<int>());
    fo(i,n){
        val=m[i];
        // deb2(val,c[val-1]);
        if(v[j].size()==c[val-1]){
            j++;
            if(j==mx){
                j=0;
            }
        }
        v[j].pb(val);
    }

    fo(i,mx){
        cout<<v[i].size()<<" ";
        fo(j,v[i].size()){
            cout<<v[i][j]<<" ";
        }cout<<nl;
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

