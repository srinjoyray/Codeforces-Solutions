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
void solve(){
    int i,j;
    int n,m,temp;
    cin>>n>>m;
    map<int,vi> adj;
    fo(i,m){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    map<int,string> mapp;
    map<int,int> val,freq; 
    mapp[1]="";mapp[2]="";mapp[3]="";

    fo2(i,1,n){
        string s;
        vi curr;
        for(auto child : adj[i]){
            curr.pb(child);
        }
        sort(all(curr));
        
        fo(j,curr.size()){
            s+=to_string(curr[j]);
            s+='_';
        }
        if(mapp[1]=="" || mapp[1]==s){
            val[i]=1;
            freq[1]++;
            mapp[1]=s;
        }
        else if(mapp[2]=="" || mapp[2]==s){
            val[i]=2;
            freq[2]++;
            mapp[2]=s;
        }
        else if(mapp[3]=="" || mapp[3]==s){
            val[i]=3;
            freq[3]++;
            mapp[3]=s;
        }
        else{
            cout<<"-1\n";
            return;
        }
        // deb2(i,val[i]);
        // deb(s);
    }

    if(mapp[1]=="" || mapp[2]=="" || mapp[3]==""){
        cout<<"-1\n";
        return;
    }
    fo2(i,1,3){
        temp=n-freq[i];
        string s=mapp[i];
        fo(j,s.size()){
            if(s[j]=='_'){
                temp--;
            }
        }
        if(temp!=0){
            cout<<"-1\n";
            return;
        }
    }

    fo2(i,1,n){
        cout<<val[i]<<" ";
    }cout<<nl;

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

