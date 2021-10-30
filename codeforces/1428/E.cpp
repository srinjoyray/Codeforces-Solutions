#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fo(i,n) for(i=0;i<n;i++)
#define fo2(i,start,end) for(i=start;i<=end;i++)
#define rfo(i,n) for(i=n-1;i>=0;i--)
#define deb(x) cout<<#x<<"="<<x<<endl
#define deb2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
#define ll long long
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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

const int N=1e6+10;
ll calc(ll num, ll pieces){
    ll low,rem,ans;
    low=num/pieces;

    rem=num-low*pieces;

    ans=rem*(low+1)*(low+1) + (pieces-rem)*(low)*(low);

    // deb2(num,pieces);
    // deb(ans);
    return ans;
}
void solve(){
    int i,j;
    int n,k;
    cin>>n>>k;
    ll a[n],curr,temp,value,pieces,rem,div,ans=0;
    fo(i,n){
        cin>>a[i];
    }
    set<pair<pl,pl>> se;
    // {{value,index},{a[index],pieces}}
    fo(i,n){
        temp=calc(a[i],1)-calc(a[i],2);
        se.insert({{temp,i},{a[i],1}});
    }
    // for(auto it :  se){
    //     cout<<it.F.F<<" "<<it.F.S<<" "<<it.S.F<<" "<<it.S.S<<nl;
    // }
    curr=n;
    // deb(curr);
    while(curr<k){
        pair<pl,pl> p;
        p=*se.rbegin();
        se.erase(*se.rbegin());

        temp=calc(p.S.F,p.S.S+1)-calc(p.S.F,p.S.S+2);
        se.insert({{temp,p.F.S},{p.S.F,p.S.S+1}});  
        curr++;  
    }

    // for(auto it :  se){
    //     cout<<it.F.F<<" "<<it.F.S<<" "<<it.S.F<<" "<<it.S.S<<nl;
    // }
    for(auto it :  se){
        value=it.S.F;
        pieces=it.S.S;

        temp=calc(value,pieces);
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

