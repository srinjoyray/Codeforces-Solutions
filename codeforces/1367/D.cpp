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
    string s,ans;
    cin>>s;
    int n;
    cin>>n;
    int b[n],temp,count,start=25;
    char ch;
    fo(i,n){
        cin>>b[i];
        ans.pb('-');
    }
    map<char,int> mapp;
    vi v;
    fo(i,s.size()){
        mapp[s[i]]++;
    }    
    
    while(true){
        v.clear();
        fo(i,n){
            if(b[i]==0){
                v.pb(i);
            }
        }
        count=v.size();
        // deb(count);
        if(count==0){
            break;
        }
        for(i=start;i>=0;i--){
            if(mapp['a'+i]>=count){
                mapp['a'+i]=0;
                ch='a'+i;
                start=i-1;
                break;
            }
        }
        // deb(ch);

        fo(i,v.size()){
            ans[v[i]]=ch;
            b[v[i]]=-1;
        }

        fo(i,n){
            if(b[i]==-1){
                continue;
            }
            fo(j,v.size()){
                if(i==v[j]){
                    break;
                }
            }
            if(j!=v.size()){
                continue;
            }
            temp=0;
            fo(j,v.size()){
                temp+=abs(i-v[j]);
            }
            b[i]-=temp;
        }
        // deb(ans);
    }
    cout<<ans<<nl;
        
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

