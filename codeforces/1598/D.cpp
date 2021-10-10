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
    ll n;
    cin>>n;
    ll a[n],b[n],val,temp,ans=0,first=0,second=0,third=0,fail=0,l,r;
    fo(i,n){
        cin>>a[i]>>b[i];
    }
    set<ll> se;
    map<ll,vl> mapp;
    map<ll,ll> mp2;
    fo(i,n){
        se.insert(a[i]);
        mapp[a[i]].pb(b[i]);
        mp2[b[i]]++;
    }
    fo(i,n){
        l=mapp[a[i]].size()-1;
        r=mp2[b[i]]-1;
        temp=l*r;
        fail+=temp;
    }
    ans=(n*(n-1)*(n-2))/6;
    ans-=fail;
    cout<<ans<<nl;
    // // 1:3
    // for(auto it :  se){
    //     val=mapp[it].size();
    //     if(val>=3){
    //         temp=(val*(val-1)*(val-2))/6;
    //         first+=temp;
    //     }
    // }
    // // 2:3
    // for(auto it :  se){
    //     val=mapp[it].size();
    //     if(val>=2){
    //         temp=(val*(val-1)/2)*(n-val);
    //         // deb(temp);
    //         second+=temp;
    //         fo(j,val){
    //             temp=(val-1)*(mp2[mapp[it][j]]-1);
    //             // deb(temp);
    //             second-=temp;
    //         }
    //     }
    // }
    // // deb2(first,second);
    // // 3:k
    // val=se.size();
    // third=(val*(val-1)*(val-2))/6;
    // for(auto it : se){
    //     third*=mapp[it].size();
    // }
    // // deb(third);
    
    // for(auto it :  se){
    //     // deb(it);
    //     val=mapp[it].size();
    //     if(val>=2){     
    //         fo(j,val){
    //             temp=(val-1)*(mp2[mapp[it][j]]-1);
    //             // deb2(temp,mapp[it][j]);
    //            fail+=temp;
    //         }
    //     }
    // }
    // // deb(fail);
    // ans=(n*(n-1)*(n-2))/6;
    // ans-=fail;
    // cout<<ans<<nl;
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

