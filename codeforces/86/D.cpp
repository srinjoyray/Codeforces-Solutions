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
ll a[N];
struct node{
    ll l,r,idx;
}q[N];

ll sz=500,power=0,freq[N]={0};

bool comp(node a, node b){
    if(a.l/sz!=b.l/sz){
        return a.l/sz<b.l/sz;
    }
    return a.r<b.r;
}
void add(ll pos){
    ll prev=freq[a[pos]];
    ll curr=prev+1;
    freq[a[pos]]++;
    power+=a[pos]*((curr*curr)-(prev*prev));
}

void remove(ll pos){
    ll prev=freq[a[pos]];
    ll curr=prev-1;
    freq[a[pos]]--;
    power+=a[pos]*((curr*curr)-(prev*prev));
}

void solve(){
    int i,j;
    int n,m;
    cin>>n>>m;
    fo(i,n){
        cin>>a[i];
    }
    fo(i,m){
        ll l,r;
        cin>>l>>r;
        l--,r--;
        q[i].l=l, q[i].r=r;
        q[i].idx=i;
    }
    ll ans[m];
    sort(q,q+m,comp);
    int left=0,right=-1;
    fo(i,m){
        int l,r;
        l=q[i].l;
        r=q[i].r;

        while(left>l){
            left--;
            add(left);
        }
        while(left<l){
            remove(left);
            left++;
        }

        while(right<r){
            right++;
            add(right);
        }
        while(right>r){
            remove(right);
            right--;
        }

        ans[q[i].idx]=power;
    }

    fo(i,m){
        cout<<ans[i]<<nl;
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
    
}

