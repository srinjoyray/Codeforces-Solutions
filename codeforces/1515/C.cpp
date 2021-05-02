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
bool comp(pl a,pl b){
    if(a.F==b.F){
        return a.S<b.S;
    }
    return a.F>b.F;
}
void solve(){
    int i,j;
    lli n,m,x;
    cin>>n>>m>>x;
    lli temp,ans[n]={0},temp_pos;
    vpl h;
    // set<pii> s;
    // set<pii>::iterator it;
    fo(i,n){
        cin>>temp;
        h.pb({temp,i});
    }
    sort(all(h),comp);
    fo(i,n){
        // deb2(h[i].F,h[i].S);
    }
    fo(i,n){
        ans[h[i].S]=i%m;
    }
    cout<<"YES\n";
    fo(i,n){
        cout<<ans[i]+1<<" ";
    }cout<<nl;
    /*fo(i,m){
        s.insert({h[i].F,i});
        ans[h[i].S]=i;
        // deb2(h[i].F,i);
    }
    if(m==1){
        cout<<"YES\n";
        fo(i,n){
            cout<<"1 ";
        }
        cout<<nl;
        return;
    }
    fo2(i,m,n-1){
        temp=(*s.begin()).F;
        temp+=h[i].F;
        temp_pos=(*s.begin()).S;
        // deb2(temp,temp_pos);
        s.erase(s.begin());
        s.insert({temp,temp_pos});
        ans[h[i].S]=temp_pos;
    }
    for(it=s.begin();it!=s.end();it++){
        // deb2((*it).F,(*it).S);
    }
    // deb((*s.rbegin()).F);
    if(((*s.rbegin()).F-(*s.begin()).F)<=x){
        cout<<"YES\n";
        fo(i,n){
            cout<<ans[i]+1<<" ";
        }
        cout<<nl;
    }
    else{
        cout<<"NO\n";
    }*/
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

