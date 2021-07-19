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
int seg[2 * N];
// build the tree (n=size of segtree)
void build(int a[],int n) {  
    for(int i=0;i<n;i++){
        seg[n+i]=a[i];
    }
    int type=1,temp;
    for (int i=n-1;i>0;--i){
        if(type==1){
            seg[i] = seg[2*i] | seg[2*i+1];
        }
        else{
            seg[i] = seg[2*i] ^ seg[2*i+1];
        }
        temp=i;
        while(temp%2==0){
            temp/=2;
        }
        if(temp==1){
            type^=1;
        }
    } 
}
// set value at position p
void modify(int p, int val,int n) {  
    // for (seg[p += n] = value; p > 1; p >>= 1) 
    //     seg[p>>1] = seg[p] | seg[p^1];

    p+=n;
    seg[p]=val;
    p/=2;
    int i=0;
    while(p>0){
        if(i%2==0){
            seg[p]=seg[2*p]|seg[2*p+1];
        }
        else{
            seg[p]=seg[2*p]^seg[2*p+1];
        }
        i++;
        p/=2;
    }
}


void solve(){
    int i,j;
    int n,m;
    cin>>n>>m;
    n=pow(2,n);
    int a[n];
    fo(i,n){
        cin>>a[i];
    }
    build(a,n);
    // fo2(i,1,7){
    //     cout<<seg[i]<<" ";
    // }cout<<nl;
    while(m--){
        int pos,val,ans;
        cin>>pos>>val;
        pos--;
        modify(pos,val,n);
        ans=seg[1];
        // fo2(i,1,7){
        //     cout<<seg[i]<<" ";
        // }cout<<nl;
        cout<<ans<<nl;
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

