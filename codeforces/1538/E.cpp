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
int check(string a,string b){
    // deb2(a,b);
    ll n=a.size();
    ll ans=0;
    if(n>=1 && b.size()>=3){
        if(a[n-1]=='h' && b[0]=='a' && b[1]=='h' && b[2]=='a'){
            ans++;
        }
    }
    if(n>=2 && b.size()>=2){
        if(a[n-2]=='h' && a[n-1]=='a' && b[0]=='h' && b[1]=='a'){
            ans++;
        }
    }
    if(n>=3 && b.size()>=1){
        if(a[n-3]=='h' && a[n-2]=='a' && a[n-1]=='h' && b[0]=='a'){
            ans++;
        }
    }
    return ans;
    // 1 3
    // 2 2
    // 3 1
}
string change(string s){
    string a;
    ll n=s.size();
    a.pb(s[0]);
    a.pb(s[1]);
    a.pb(s[2]);

    a.pb(s[n-3]);
    a.pb(s[n-2]);
    a.pb(s[n-1]);
    return a;
}
void solve(){
    int i,j;
    int n;
    cin>>n;
    map<string,string> mapp;
    map<string,ll> val;
    ll ans=0,temp;
    fo(i,n){
        string s,op;
        cin>>s;
        cin>>op;
        if(op=="="){
            string a,b,del;
            cin>>a>>del>>b;
            
            val[s]=val[a]+val[b];
            temp=check(mapp[a],mapp[b]);
            val[s]+=temp;
            mapp[s]=mapp[a]+mapp[b];
            if(mapp[s].size()>=6){
                mapp[s]=change(mapp[s]);
            }
        }
        else{
            string a;
            cin>>a;
            int count=0;
            mapp[s]=a;
            for(j=3;j<a.size();j++){
                if(a[j]=='a' && a[j-1]=='h' && a[j-2]=='a' && a[j-3]=='h'){
                    count++;
                }
            }
            val[s]=count;
        
        }
        ans=val[s];
        // deb(s);
        // deb2(mapp[s],val[s]);
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

