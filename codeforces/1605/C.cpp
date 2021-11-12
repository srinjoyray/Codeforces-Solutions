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
    string s;
    cin>>s;
    int pref1[n+1]={0},pref2[n+1]={0},pref3[n+1]={0};
    int a=0,b=0,c=0,ans=n+1,temp;
    vi v;
    
    fo(i,n){
        pref1[i+1]+=pref1[i];
        pref2[i+1]+=pref2[i];
        pref3[i+1]+=pref3[i];

        if(s[i]=='a'){
            pref1[i+1]++;
            v.pb(i+1);
        }
        else if(s[i]=='b'){
            pref2[i+1]++;
        }
        else{
            pref3[i+1]++;
        }
    }
    // deb(v.size());
    if(v.size()==0){
        cout<<"-1\n";
        return;
    }
    for(i=0;i<v.size()-1;i++){
        a=pref1[v[i+1]]-pref1[v[i]-1];
        b=pref2[v[i+1]]-pref2[v[i]-1];
        c=pref3[v[i+1]]-pref3[v[i]-1];
       
        if(a>b && a>c){
            temp=v[i+1]-v[i]+1;
            ans=min(ans,temp);
        }

        if(i<v.size()-2){
            
            a=pref1[v[i+2]]-pref1[v[i]-1];
            b=pref2[v[i+2]]-pref2[v[i]-1];
            c=pref3[v[i+2]]-pref3[v[i]-1];

            if(a>b && a>c){
                temp=v[i+2]-v[i]+1;
                ans=min(ans,temp);
            }
        }

        // deb(ans);
    }
    // deb(ans);
    if(ans>n){
        ans=-1;
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

