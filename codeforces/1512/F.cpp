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
    ll n,c;
    cin>>n>>c;
    ll a[n],b[n-1];
    fo(i,n){
        cin>>a[i];
    }
    fo(i,n-1){
        cin>>b[i];
    }
    ll mn=INT64_MAX,count,curr=0,coins=0,rem,temp;
   
    fo(i,n){
        // deb2(coins,curr);
        rem=c-coins;
        count=curr+(rem+a[i]-1)/a[i];
        mn=min(mn,count);
        // deb(count);
        if(coins<b[i]){
            temp=(b[i]-coins+a[i]-1)/a[i];
            curr+=temp;
            coins+=temp*a[i];
        }
        curr++;
        coins-=b[i];

    }
    cout<<mn<<nl;
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

