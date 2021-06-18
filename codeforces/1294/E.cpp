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
int func(vi v,int m){
    int i,j,n,temp,pos,diff;
    n=v.size();
    map<int,int> mapp;
    fo(i,n){
        // deb(v[i]);
        if(v[i]>=0 && v[i]%m==0 && v[i]<=(n-1)*m){
            pos=v[i]/m;
            if(i>=pos){
                diff=i-pos;
            }
            else{
                diff=i+(n-pos);
            }
            // deb2(pos,diff);
            mapp[diff]++;
        }
    }
    int mn=n;
    fo(i,n+1){
        temp=i+(n-mapp[i]);
        mn=min(mn,temp);
    }
    return mn;
}
void solve(){
    int i,j;
    int n,m;
    cin>>n>>m;
    int a[n][m],temp,ans=0;
    fo(i,n){
        fo(j,m){
            cin>>a[i][j];
        }
    }
    fo(j,m){
        vi curr;
        fo(i,n){
            temp=a[i][j]-j-1;
            curr.pb(temp);
        }
        temp=func(curr,m);
        // deb(temp);
        ans+=temp;
    }
    cout<<ans<<nl;
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

