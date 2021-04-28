#include<bits/stdc++.h>
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define fo2(i,start,end) for(i=start;i<=end;i++)
#define rfo(i,n) for(i=n-1;i>=0;i--)
#define lli long long int
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
typedef pair<lli, lli>	pl;
typedef vector<int>		vi;
typedef vector<lli>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
void solve(){
    int i,j;
    int n,t,pos;
    double avg;
    lli sum=0,temp=0,x,k;
    cin>>n;
    vector<lli> v,add;
    v.pb(0);
    add.pb(0);
    fo(i,n){
        cin>>t;
        if(t==1){
            cin>>pos>>x;
            sum+=(pos*x);
            add[pos-1]+=x;
        }
        else if(t==2){
            cin>>k;
            v.pb(k);
            add.pb(0);
            sum+=k;
        }
        else if(t==3){
            temp=add[add.size()-1]; 
            add[add.size()-2]+=temp;
            add.erase(add.begin()+add.size()-1);
            sum-=temp;
            temp=v[v.size()-1];
            sum-=temp;
            v.erase(v.begin()+v.size()-1);
        }
        if(v.size()==0){
            avg=0;
        }
        else{
            avg=double(sum)/double(v.size());
        }
        cout<<fixed<<setprecision(6)<<avg<<nl;
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
    return 0;
}

