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
map<int,pii> adj;
map<int,ll> val,vis;
string temp_s;
ll func(int i,int n){
    vis[i]=1;
    if(2*i+2>=n){
        if(temp_s[i]=='?'){
            return val[i]=2;
        }
        else{
            return val[i]=1;
        }
    }
    if(temp_s[i]=='1'){
        return val[i]=func(2*i+1,n);
    }
    else if(temp_s[i]=='0'){
        return val[i]=func(2*i+2,n);
    }
    else{
        return val[i]=func(2*i+1,n)+func(2*i+2,n);
    }
}
void change(int pos){
    int parent,l,r;
    if(pos==0){
        return;
    }
    parent=(pos-1)/2;
    

    if(temp_s[parent]=='1'){
        val[parent]=val[2*parent+1];
    }
    else if(temp_s[parent]=='0'){
        val[parent]=val[2*parent+2];
    }
    else{
        val[parent]=val[2*parent+1]+val[2*parent+2];
    }
    change(parent);
}
void solve(){
    int i,j;
    int k,q,n,temp;
    cin>>k;
    string s;
    cin>>s;
    n=s.size();
    temp_s=s;
    reverse(all(temp_s));
    // deb(temp_s);
    pii pa;
    for(i=0;i<n;i++){
        pa.S=2*i+1;
        pa.F=2*i+2;
        adj[i]=(pa);
    }
    vis.clear();
    fo(i,n){
        if(vis[i]==0){
            temp=func(i,n);
        }
    }
    /*fo(i,n){
        cout<<val[i]<<" ";
    }cout<<nl;*/
    ll ans;
    cin>>q;
    while(q--){
        int p,rev_p;
        char c;
        cin>>p>>c;

        rev_p=n-p;
        temp_s[rev_p]=c;
        if(2*rev_p+2>n){
            if(c=='?'){
                val[rev_p]=2;
            }
            else{
                val[rev_p]=1;
            }
           
        }
        else if(c=='?'){
            val[rev_p]=val[2*rev_p+1]+val[2*rev_p+2];
        }
        else if(c=='1'){
            val[rev_p]=val[2*rev_p+1];
        }
        else{
            val[rev_p]=val[2*rev_p+2];
        }
        change(rev_p);
       
        s[p-1]=c;
        
        // deb(temp_s);
        
        /*fo(i,n){
            cout<<val[i]<<" ";
        }cout<<nl;*/
        
        ans=val[0];
        cout<<ans<<nl;
    }
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}

