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
    int n,count=0;
    cin>>n;
    string s,a;
    cin>>s;
    a=s;
    sort(all(a));
    // deb2(s,a);
    fo(i,s.size()){
        if(s[i]=='0'){
            count++;
        }
    }
    // deb(count);
    vector<vi> ans;
    while(true){
        if(s==a){
            break;
        }
        vi v,v1,v2;
        fo(i,count){
            if(s[i]=='1'){
                v1.pb(i);
            }
        }
        fo2(i,count,n-1){
            if(s[i]=='0'){
                v2.pb(i);
            }
        }
        // deb2(v1.size(),v2.size());
        fo(i,min(v1.size(),v2.size())){
            v.pb(v1[i]);
        }
        fo(i,min(v1.size(),v2.size())){
            v.pb(v2[i]);
        }
        // fo(i,v1.size()){
        //     cout<<v1[i]<<"#";
        // }cout<<nl;
        // fo(i,v2.size()){
        //     cout<<v2[i]<<"@";
        // }cout<<nl;
        ans.pb(v);
        i=0;j=v.size()-1;
        while(i<=j){
            // deb2(v[i],v[j]);
            swap(s[v[i]],s[v[j]]);
            i++,j--;
        }
        // deb(s);
        // break;
    }
    cout<<ans.size()<<nl;;
    fo(i,ans.size()){
        cout<<ans[i].size()<<" ";
        fo(j,ans[i].size()){
            cout<<ans[i][j]+1<<" ";
        }cout<<nl;
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

