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
typedef struct node node;
struct node{
    ll a,b,m,index;
};
ll total;
vl values(N);
void helper(vector<node> v){
    int i,j;
    // fo(i,v.size()){
    //     cout<<v[i].a<<" "<<v[i].b<<" "<<v[i].m<<" "<<v[i].index<<nl;
    // }
    set<pair<pii,int>> se;
    fo(i,v.size()){
       ll l,r;
       l=max(v[i].a-v[i].m,(ll)0);
       r=v[i].a-(v[i].m-min(v[i].b,v[i].m));
    //    deb2(l,r); 
       se.insert({{r,l},v[i].index});
    }
    set<int> s1;
    map<int,int> mp;
    for(auto it : se){
        ll l,r;
        l=it.F.S;
        r=it.F.F;
        if(s1.lower_bound(l)==s1.end()){
            s1.insert(r);
            mp[it.S]=r;
        }
        else{
            mp[it.S]=*s1.lower_bound(l);
        }
    }
    total+=s1.size();

    for(auto it :  mp){
        values[it.F]=it.S;
    }

}
void solve(){
    int i,j;
    int n;
    cin>>n;
    ll a[n],b[n],m[n],temp;
    fo(i,n){
        cin>>a[i]>>b[i]>>m[i];
    }
    map<ll,vector<node>> mapp;
    fo(i,n){
        node p;
        p.a=a[i],p.b=b[i],p.m=m[i],p.index=i;
        mapp[a[i]+b[i]-m[i]].pb(p);
    }
    total=0;
    for(auto it : mapp){
        // deb(it.F);
        helper(mapp[it.F]);
    }
    cout<<total<<nl;
    fo(i,n){
        temp=a[i]-values[i];
        cout<<temp<<" "<<m[i]-temp<<nl;
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

