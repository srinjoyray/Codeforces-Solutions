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
int m,n;
ll c[11],inp,suff[12],b[N][11],temp,mx;
vl v[11],ans;
map<string,ll> mapp;
string s1;
void find(string s,int idx,ll val){
    int i,j;
    if(idx==n){
        return;
    }
    string temp_s;
    fo(j,c[idx]){
        temp_s=s;
        temp_s+=to_string(j)+"_";
        // deb(temp_s);
        if(mapp[temp_s]==0){
            temp=val+v[idx][j]+suff[idx+1];
            if(temp>mx){
                s1=temp_s;
                mx=temp;
            }
            break;
        }
        else{
            find(temp_s,idx+1,val+v[idx][j]);
        }
    }
}
void solve(){
    int i,j;
    
    cin>>n;
    fo(i,n){
        v[i].clear();
    }
    
    fo(i,n){
        cin>>c[i];
        fo(j,c[i]){
            cin>>inp;
            v[i].pb(inp);
        }
        sort(all(v[i]),greater<ll>());
    }
    suff[n]=0;
    for(i=n-1;i>=0;i--){
        suff[i]=suff[i+1]+v[i][0];
    }

    // fo(i,n){
    //     cout<<suff[i]<<" ";
    // }cout<<nl;

    
    cin>>m;
    string s,temp_s;
    fo(i,m){
        s="";
        fo(j,n){
            cin>>b[i][j];
            b[i][j]=c[j]-b[i][j];
            
            temp_s=to_string(b[i][j]);
            temp_s+="_";
            s+=temp_s;

            mapp[s]++;
        }
        
    }
    mx=0;
    
    s="";
    
    find(s,0,0);

    // deb(s1);
    ans.clear();
    ll curr=0,dig;
    fo(i,s1.size()){
        if(s1[i]!='_'){
            dig=s1[i]-'0';
            curr=(curr*10)+dig;
        }
        else{
            ans.pb(curr);
            curr=0;
        }
    }
    while(ans.size()<n){
        ans.pb(0);
    }
    fo(i,ans.size()){
        ans[i]=c[i]-ans[i];
    }
    
    fo(i,ans.size()){
        cout<<ans[i]<<" ";
    }cout<<nl;
    // cout<<mx<<nl;
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

