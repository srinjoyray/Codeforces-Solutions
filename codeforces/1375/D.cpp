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
    int a[n],mex,temp;
    vi v;
    fo(i,n){
        cin>>a[i];
    }
    set<int> left;
    fo(i,n){
        if(a[i]!=i){
            left.insert(i);
        }
    }

    while(true){
        if(is_sorted(a,a+n)){
            break;
        }
        map<int,int> mapp;
        fo(i,n){
            mapp[a[i]]++;
        }
        fo(i,n+1){
            if(mapp[i]==0){
                mex=i;
                break;
            }
        }   
        // deb(mex);
        if(mex==n){
            temp=*left.begin();
            a[temp]=mex;
            v.pb(temp+1);
        }
        else{
            a[mex]=mex;
            left.erase(mex);
            v.pb(mex+1);
        }
    }

    // fo(i,n){
    //     cout<<a[i]<<" ";
    // }cout<<nl;

    cout<<v.size()<<nl;
    fo(i,v.size()){
        cout<<v[i]<<" ";
    }cout<<nl;
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

