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

map<pl,lli> vis;
map<lli,lli> present;
void check(vl v){
    // deb2(l,r);
    if(v.size()==0){
        return ;
    }

    lli sum=0;
    
    lli mid,pos,i,j,n;
    n=v.size();
    fo(i,v.size()){
        sum+=v[i];
    }
    // deb2(sum,n);
    present[sum]++;
    mid=(v[0]+v[n-1])/2;
    pos=upper_bound(all(v),mid)-v.begin()-1;
    vl temp1,temp2;
    fo(i,v.size()){
        if(i<=pos){
            temp1.pb(v[i]);
        }
        else{
            temp2.pb(v[i]);
        }
    }
    if(temp1.size()<n){
        check(temp1);
    }
    if(temp2.size()<n){
        check(temp2);
    }
    
}
void solve(){
    int i,j;
    int n,q;
    cin>>n>>q;
    lli temp,sum,left,right,pos;
    vl v;
    fo(i,n){
        cin>>temp;
        // temp=2;
        v.pb(temp);
    }
    sort(all(v));

    vis.clear();
    present.clear();
    check(v);
    // deb(present.size());
    while(q--){
        cin>>sum;
        // deb(sum);
        if(present[sum]>0){
            cout<<"Yes\n";
        }
        else{
            cout<<"No\n";
        }
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
    return 0;
}

