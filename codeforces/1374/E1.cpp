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
bool comp(pair<int,pl> a, pair<int,pl> b){
    if(a.F==b.F){
        return ((a.S.F+a.S.S)>(b.S.F+b.S.S));
    }
    return a.F<b.F;
}
void solve(){
    int i,j,z;
    int n,k;
    cin>>n>>k;
    vi v1,v2,v3;
    int a,b,temp,count,ans=0,rem,upto;
    map<int,int> mapp;
    fo(i,n){
        cin>>temp>>a>>b;
        if(a==1 && b==1){
            v3.pb(temp);
        }
        else if(a==1){
            v1.pb(temp);
        }
        else if(b==1){
            v2.pb(temp);
        }
    }
    sort(all(v1));
    sort(all(v2));
    sort(all(v3));
    if(min(v1.size(),v2.size())+v3.size()<k){
        cout<<"-1\n";
        return;
    }
    temp=min(v1.size(),v2.size());
    upto=min(temp,k);
    rem=k-upto;
    fo(i,rem){
        ans+=v3[i];
    }
    fo(i,upto){
        ans+=v1[i];
        ans+=v2[i];
    }
    i=upto-1;
    j=upto-1;
    z=rem;
    while(i>=0 && j>=0 && z<v3.size()){
        temp=v1[i]+v2[j];
        if(temp<=v3[z]){
            break;
        }
        else{
            ans+=v3[z]-(temp);
            i--;
            j--;
            z++;
        }
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
    return 0;
}

