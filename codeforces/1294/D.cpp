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
    return a.F<b.F;
}
void solve(){
    int i,j;
    int q,x;
    cin>>q>>x;
    lli mex,temp,last[x]={0};
    set<pl>se;
    set<pl>::iterator itr;
    fo(i,x){
        se.insert({0,i});
    }
    /*for(itr=se.begin();itr!=se.end();itr++){
        cout<<(*itr).F<<" "<<(*itr).S<<nl;
    }*/
    while(q--){
        cin>>temp;
        // temp=1;
        temp%=x;
        last[temp]++;
        se.erase({last[temp]-1,temp});
        se.insert({last[temp],temp});
        mex=(*se.begin()).S+x*((*se.begin()).F);
        cout<<mex<<nl;

        /*for(itr=se.begin();itr!=se.end();itr++){
            cout<<(*itr).F<<" "<<(*itr).S<<nl;
        }*/
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

