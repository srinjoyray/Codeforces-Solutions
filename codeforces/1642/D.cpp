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
vpl v1;
vl v2;
void find(ll pos,ll &start,ll end,ll a[],ll n){
    ll i,j;
    // deb2(pos,end);
    fo2(i,1,pos){
        v1.pb({a[i],pos+i+start-1});
    }
    start+=2*pos;

    i=1,j=pos;
    while(i<j){
        swap(a[i],a[j]);
        i++,j--;
    }
    // fo2(i,1,n){
    //     cout<<a[i]<<"@";
    // }cout<<nl;
    fo2(i,1,end-1){
        v1.pb({a[i],end-1+i+start-1});
    }
    start+=2*(end-1);

    i=1;j=end-1;
    while(i<=j){
        swap(a[i],a[j]);
        i++,j--;
    }

    // fo2(i,1,n){
    //     cout<<a[i]<<"#";
    // }cout<<nl;
}
void solve(){
    int i,j;
    ll n;
    cin>>n;
    ll a[n+1];
    set<int>se;
    fo2(i,1,n){
        cin>>a[i];
    }
    fo2(i,1,n){
        if(se.find(a[i])!=se.end()){
            se.erase(a[i]);
        }
        else{
            se.insert(a[i]);
        }
    }
    if(se.size()>0){
        cout<<"-1\n";
        return;
    }
    v1.clear() , v2.clear();
    ll start=0,end=n,pos;
    while(end>0){
        // fo2(i,1,n){
        //     cout<<a[i]<<" ";
        // }cout<<nl;
        fo2(i,1,n){
            if(a[i]==a[end]){
                pos=i;
                break;
            }
        }
        find(pos,start,end,a,n);
        v2.pb(2*pos);
        v2.pb(2*(end-1));

        
        

        end-=2;
    }
    fo2(i,1,n/2){
        v2.pb(2);
    }

    cout<<v1.size()<<nl;
    fo(i,v1.size()){
        cout<<v1[i].S<<" "<<v1[i].F<<nl;
    }
    cout<<v2.size()<<nl;
    fo(i,v2.size()){
        cout<<v2[i]<<" ";
    }cout<<nl;
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
    
}

