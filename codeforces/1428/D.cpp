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
    int n;
    cin>>n;
    int a[n+1];
    fo2(i,1,n){
        cin>>a[i];
    }
    vpii ans;
    int count=n;
    vi rest,one,h(n+1);
    for(i=n;i>=1;i--){
        int pair=-1;
        if(a[i]==2){
            if(one.size()==0){
                cout<<"-1\n";
                return;
            }
            pair=one.back();
            one.pop_back();
        }
        if(a[i]==3){
            if(rest.size()>0){
                pair=rest.back();
                rest.pop_back();
            }
            else if(one.size()>0){
                pair=one.back();
                one.pop_back();
            }
            else{
                cout<<"-1\n";
                return;
            }
        }

        if(a[i]==1){
            one.pb(i);
            h[i]=count;
            count--;
            ans.pb({h[i],i});
        }
        if(a[i]==2){
            rest.pb({i});
            h[i]=h[pair];
            ans.pb({h[i],i});
        }
        if(a[i]==3){
            rest.pb(i);
            h[i]=count;
            count--;
            ans.pb({h[i],i});
            ans.pb({h[i],pair});
        }
    }
    cout<<ans.size()<<nl;
    fo(i,ans.size()){
        cout<<ans[i].F<<" "<<ans[i].S<<nl;
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

