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
    int n,d;
    cin>>n>>d;
    int a[n],ini,pos;
    set<int> s1,s2,s3;
    fo(i,n){
        cin>>a[i];
        if(a[i]==0){
            s1.insert(i);
        }
        else{
            s2.insert(i);
        }
    }
    if(s2.size()==0){
        cout<<"0\n";
        return;
    }
  
    fo2(i,1,2*n){
        ini=s2.size();
        // for(auto p :  s1){
        //     cout<<p<<"@";
        // }cout<<nl;
        // for(auto p :  s2){
        //     cout<<p<<"#";
        // }cout<<nl;
        for(auto p : s1){
            pos=(p+d)%n;
            // deb2(p,pos);
            if(s2.find(pos)!=s2.end()){
                s2.erase(pos);
                s3.insert(pos);
            }
        }
        // for(auto p :  s3){
        //     cout<<p<<"!";
        // }cout<<nl;
        if(s2.size()==0){
            cout<<i<<nl;
            return;
        }
        if(ini==s2.size()){
            cout<<"-1\n";
            return;
        }
        s1=s3;
        s3.clear();
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
// test