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

void solve(){
    int i,j;
    int n;
    cin>>n;
    int a[n],b[n];
    bool flag=false;
    fo(i,n){
        cin>>a[i];
    }
   
    fo(i,n){
        b[i]=a[i];
    }
    sort(b,b+n);
    
    map<int,set<int>> se;
    
    fo(i,n){
        se[a[i]].insert(i);
        if(se[a[i]].size()>1){
            flag=true;
        }
    }
    if(flag){
        cout<<"YES\n";
        return;
    }
    ll pos,val,extra;

    fo(i,n-2){
        // deb(i);
        if(b[i]==a[i]){
            se[a[i]].erase(i);
            continue;
        }
        val = b[i];
        pos = *se[val].lower_bound(i); 
        if(pos!=i+1){
            extra = i+1;      
        }
        else{       
            extra = i+2;
        }

        // deb2(pos,extra);

        se[a[i]].erase(i);
        se[val].erase(pos);
        se[a[extra]].erase(extra);

        a[pos]=a[extra];
        a[extra]=a[i];
        a[i]=val;

        se[a[extra]].insert(extra);
        se[a[pos]].insert(pos);
       
    }   
    // fo(i,n){
    //     cout<<a[i]<<" ";
    // }cout<<nl;

    if(is_sorted(a,a+n)){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
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

