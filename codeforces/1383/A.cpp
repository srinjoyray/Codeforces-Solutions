#include<bits/stdc++.h>
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define fo2(i,start,end) for(i=start;i<=end;i++)
#define rfo(i,n) for(i=n-1;i>=0;i--)
#define ll long long int
#define deb(x) cout<<#x<<"="<<x<<endl
#define deb2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
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
const int N=1e6+10;

void solve(){
    int i,j;
    int n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    set<pii> se,temp;
    fo(i,n){
        if(a[i]>b[i]){
            cout<<"-1\n";
            return;
        }
        if(a[i]==b[i]){
            continue;
        }
        se.insert({a[i]-'a',b[i]-'a'});
    }

    int ans=0,start,end;
    while(se.size()){
        start=(*se.begin()).F;
        end=(*se.begin()).S;
        // deb2(start,end);
        temp.clear();
        for(auto p : se){
            // deb2(p.F,p.S);
            if(p.F==start && p.S==end){
                continue;
            }
            if(p.F==start && p.S>end){
                temp.insert({end,p.S});
            }
            if(p.F>start){
                temp.insert(p);
            }
        }
        se=temp;
        ans++;
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

