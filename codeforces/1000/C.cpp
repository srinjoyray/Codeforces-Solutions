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
    int n;
    cin>>n;
    lli l[n],r[n],last,temp,curr=0,mn;
    fo(i,n){
        cin>>l[i]>>r[i];
    }
    map<lli,lli> m,add,sub;
    sort(l,l+n);
    sort(r,r+n);
    fo(i,n){
        add[l[i]]++;
        sub[r[i]]++;
    }    
    set<lli> s;
    set<lli>::iterator itr;
    fo(i,n){
        s.insert(l[i]);
        s.insert(r[i]);
    }
    last=-1;
    for(itr=s.begin();itr!=s.end();itr++){
        // deb(*itr);
        temp=(*itr)-last-1;
        m[curr]+=temp;
        // deb2(curr,temp);
        curr+=add[*itr];
        m[curr]++;
        // deb(curr);
        curr-=sub[*itr];
        // deb(curr);
        last=(*itr);
    }


    fo2(i,1,n){
        cout<<m[i]<<" ";
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
    return 0;
}

