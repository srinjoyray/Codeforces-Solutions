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
    int n;
    cin>>n;
    int a[n],temp;
    map<int,int> mapp;
    vi v;
    fo(i,n){
        cin>>a[i];
        v.pb(a[i]);
        mapp[a[i]]++;
    }
    bool flag=true;
    int k=500;
    
    while(flag && k--){
        flag=false;
        vi curr;
        fo(i,v.size()){
            for(j=i+1;j<v.size();j++){
                temp=abs(v[i]-v[j]);
               
                if(mapp[temp]==0){
                    flag=true;
                    mapp[temp]=1;
                    curr.pb(temp);
                }
            }
        }
        fo(i,curr.size()){
            v.pb(curr[i]);
        }
        
        if(v.size()>300){
            break;
        }
    }
    if(v.size()>300){
        cout<<"NO\n";
    }
    else{
        cout<<"YES\n";
        cout<<v.size()<<nl;
        fo(i,v.size()){
            cout<<v[i]<<" ";
        }cout<<nl;
    }
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

