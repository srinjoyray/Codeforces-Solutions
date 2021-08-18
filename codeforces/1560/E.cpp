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
bool check(string ans,string order,string ini){
    string s="",temp;
    int i,j;
    fo(i,order.size()){
        s+=ans;
        temp="";
        fo(j,ans.size()){
            if(ans[j]!=order[i]){
                temp.pb(ans[j]);
            }
        }
        ans=temp;
    }
    if(s==ini){
        return true;
    }
    return false;
}
void solve(){
    int i,j;
    string s,ans;
    cin>>s;
    // deb(s);
    int n;
    n=s.size();
    // deb(n);
    map<int,int> mapp,vis;
    int sz=0,count,dig;
    fo(i,n){
        mapp[s[i]-'a']++;
    }
    string order;
    for(i=n-1;i>=0;i--){
        dig=s[i]-'a';
        // deb(dig);
        if(vis[dig]==0){
            order.pb(s[i]);
            vis[dig]++;
        }
    }
    
    reverse(all(order));
    // deb(order);
    fo(i,order.size()){
        count=i+1;
        dig=order[i]-'a';
        // deb2(dig,mapp[dig]);
        if(mapp[dig]%count!=0){
            cout<<"-1\n";
            return;
        }
        sz+=mapp[dig]/count;
    }
    fo(i,sz){
        ans.pb(s[i]);
    }

    if(!check(ans,order,s)){
        cout<<"-1\n";
        return;
    }
    cout<<ans<<" "<<order<<nl;
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

