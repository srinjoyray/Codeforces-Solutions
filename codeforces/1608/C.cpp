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
    ll a[n],b[n],mx_a,mx_b,comp_a,comp_b;
    string s;
    fo(i,n){
        s.pb('0');
    }
    fo(i,n){
        cin>>a[i];
    }
    fo(i,n){
        cin>>b[i];
    }
    mx_a=*max_element(a,a+n);
    mx_b=*max_element(b,b+n);
    set<pl> s1,s2;
    fo(i,n){
        s1.insert({a[i],i});
        s2.insert({b[i],i});
    }
    comp_a=mx_a,comp_b=mx_b;
    // deb2(mx_a,mx_b);
    fo(i,n){
        if(a[i]==mx_a){
            s[i]='1';
            s1.erase({a[i],i});
            s2.erase({b[i],i});
            comp_a=min(comp_a,a[i]);
            comp_b=min(comp_b,b[i]);
            // deb(i);
        }
        else if(b[i]==mx_b){
            s[i]='1';
            s1.erase({a[i],i});
            s2.erase({b[i],i});
            comp_a=min(comp_a,a[i]);
            comp_b=min(comp_b,b[i]);
            // deb(i);
        }
    }
    int flag=1,pos;
    // deb2(comp_a,comp_b);
    while(flag){
        flag=0;
        // deb2((*s1.rbegin()).F,(*s2.rbegin()).F);
        while(s1.size() && (*s1.rbegin()).F>=comp_a){
            pos=(*s1.rbegin()).S;
            s1.erase({a[pos],pos});
            s2.erase({b[pos],pos});
            s[pos]='1';
            comp_b=min(comp_b,b[pos]);
            flag=1;
        }

        while(s2.size() && (*s2.rbegin()).F>=comp_b){
            pos=(*s2.rbegin()).S;
            s1.erase({a[pos],pos});
            s2.erase({b[pos],pos});
            s[pos]='1';
            comp_a=min(comp_a,a[pos]);
            flag=1;
        }
    }
    cout<<s<<nl;
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

