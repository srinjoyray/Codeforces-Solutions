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
bool comp(pair<lli,pair<lli,lli>> a,pair<lli,pair<lli,lli>> b){
    return a.F<b.F;
}
void solve(){
    int i,j,k;
    int n,m;
    cin>>n>>m;
    lli b[n][m],a[n][m]={0},temp,pos,l,r;
    vector<lli> v;
    vector<pair<lli,pair<lli,lli>>> vp;
    map<pair<lli,lli>,lli>mapp;
    fo(i,n){
        fo(j,m){
            cin>>b[i][j];
            vp.pb({b[i][j],{i,j}});
        }
    }
    fo(i,n){
        fo(j,m){
            a[i][j]=0;
        }
    }
    sort(all(vp),comp);
    fo(j,m){
        temp=vp[j].F;
        l=vp[j].S.F;
        r=vp[j].S.S;
        a[l][j]=temp;
        // deb2(l,j);
        // deb(temp);
        // deb2(l,r);
        mapp[{l,r}]++;
    }
    
    fo(i,n){
        k=0;
        fo(j,m){
            if(a[i][j]>0){
                continue;
            }
            while(mapp[{i,k}]>0){
                k++;
            }
            a[i][j]=b[i][k];
            // deb(k);
            // deb(a[i][j]);
            k++;
        }
    }
    fo(i,n){
        fo(j,m){
            cout<<a[i][j]<<" ";
        }
        cout<<nl;
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

