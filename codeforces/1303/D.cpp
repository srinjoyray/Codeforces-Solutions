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
string to_binary(ll n){
    string s;
    while (n > 0) {
        int dig = n % 2;
        if(dig){
            s.pb('1');
        }
        else{
            s.pb('0');
        }
        n = n / 2;
    }
    reverse(all(s));
    int rem=60-s.size(),i;
    fo(i,rem){
        s='0'+s;
    }
    return s;
}
void solve(){
    int i,j;
    ll n,m;
    cin>>n>>m;
    ll a[m];
    string s;
    fo(i,m){
        cin>>a[i];
    }
    sort(a,a+m);
    s=to_binary(n);
    reverse(all(s));
    // deb(s);

    set<ll> se;
    fo(i,s.size()){
        if(s[i]=='1'){
            se.insert(pow(2,i));
        }
    }
    ll curr=0,ans=0,temp,del,store;
    fo(i,m){
        while(se.size()>0 && *se.begin()<=curr){
            temp=*se.begin();
            curr-=temp;
            se.erase(se.begin());
        }

        // for(auto itr=se.begin();itr!=se.end();itr++){
        //     cout<<(*itr)<<" ";
        // }cout<<nl;
        // deb2(a[i],curr);

        if(se.find(a[i])!=se.end()){
            se.erase(a[i]);
            continue;
        }
        del=0;
        store=a[i];
        while(se.size()>0 && *se.begin()<a[i]){
            temp=*se.begin();
            del+=temp;
            se.erase(se.begin());
            store=min(store,temp);
            // deb2(temp,del);
        }
        ans+=log2(a[i]/store);
        curr+=a[i]-del;

        
    }
    while(se.size()>0 && *se.begin()<=curr){
        temp=*se.begin();
        curr-=temp;
        se.erase(se.begin());
    }
    if(se.size()>0){
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

