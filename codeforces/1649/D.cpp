#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fo(i,n) for(i=0;i<n;i++)
#define fo2(i,start,end) for(i=start;i<=end;i++)
#define rfo(i,n) for(i=n-1;i>=0;i--)
#define deb(x) cerr<<#x<<"="<<x<<endl
#define deb2(x,y) cerr<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
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
    int n,c,l,r;
    cin>>n>>c;
    int a[n];
    fo(i,n){
        cin>>a[i];
    }
    int freq[c+1]={0},pref[c+1]={0};
    fo(i,n){
        freq[a[i]]++;
    }
    fo2(i,1,c){
        pref[i] = pref[i-1]+freq[i];
    }

    fo2(i,1,c){
        if(freq[i]==0)continue;
        for(j=i;j<=c;j+=i){
            l=j;
            r=min(j+i-1,c);
            if(pref[r]-pref[l-1]>0 && freq[r/i]==0){
                cout<<"No\n";
                return;
            }
        }
    }

    cout<<"Yes\n";
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

