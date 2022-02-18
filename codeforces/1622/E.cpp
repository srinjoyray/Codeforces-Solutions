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
    int n,m;
    cin>>n>>m;
    ll x[n];
    string s[n];
    fo(i,n){
        cin>>x[i];
    }
    fo(i,n){
        cin>>s[i];
    }
    vi ans(m),perm(m);
    ll mx=0;
    for(int mask=0 ; mask<(1<<n) ; mask++){
        // deb(mask);
        vi v(m);
        fo(i,n){
            fo(j,m){
                if(s[i][j]=='1'){
                    if(mask&(1<<i)){
                        v[j]++;
                    }
                    else{
                        v[j]--;
                    }
                }
            }
        }
        // if(mask==1){
        //     fo(j,m){
        //         cout<<v[j]<<" ";
        //     }cout<<nl;
        // }
        vpl v1 ;
        fo(i,m){
            v1.pb({v[i],i});
        }
        sort(all(v1));
        int num=1;
        fo(i,m){
            perm[v1[i].S] = num++;
        }

        ll temp,curr=0;
        fo(i,n){
            temp=0;
            fo(j,m){
                if(s[i][j]=='1'){
                    temp+=perm[j];
                }
            }
            // if(mask==4){
            //     deb(temp);
            // }
            curr += abs(x[i]-temp);
        }
        // if(mask==1){
        //     deb(curr);
        //     fo(j,m){
        //         cout<<perm[j]<<" ";
        //     }cout<<nl;
        // }
        if(curr>=mx){
            mx=curr;
            ans=perm;
        }
    }
    fo(j,m){
        cout<<ans[j]<<" ";
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

