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
const int N=1e6;
string s,f;
int a[N],b[N],n,q;
int lazy[N],tree[N];

void build(int v,int start,int end){
    if(start==end){
        tree[v]=a[start];
        // deb2(v,a[start]);
        
    }
    else{
        int mid=(start+end)/2;
        build(2*v,start,mid);
        build(2*v+1,mid+1,end);
        tree[v]=tree[2*v]+tree[2*v+1];
    }
    
}

void push(int v,int start,int end){
    if(lazy[v]==-1){
        return ;
    }
    int wt=lazy[v]/(end-start+1);
    int mid=(start+end)/2;
    tree[2*v]=wt*(mid-start+1);
    tree[2*v+1]=wt*(end-mid);
    lazy[v]=-1;
    lazy[2*v]=tree[2*v];
    lazy[2*v+1]=tree[2*v+1];
}

int query(int v,int l,int r,int start,int end){
    if(l>r){
        return 0;
    }
    if(l==start && r==end){
        return tree[v];
    }
    else{
        push(v,start,end);
        int mid=(start+end)/2;
        return query(2*v,l,min(r,mid),start,mid)+query(2*v+1,max(mid+1,l),r,mid+1,end);
    }
}

void update(int v,int l,int r,int start,int end,int val){
    if(l>r){
        return;
    }
    // deb2(start,end);
    if(l==start && r==end){
        tree[v]=val*(end-start+1);
        lazy[v]=val*(end-start+1);
    }
    else{
        push(v,start,end);
        int mid=(start+end)/2;
        update(2*v,l,min(mid,r),start,mid,val);
        update(2*v+1,max(mid+1,l),r,mid+1,end,val);
        tree[v]=tree[2*v]+tree[2*v+1];
    }
}

void solve(){
    int i,j;
    
    cin>>n>>q;
    // deb2(n,q);
    
    cin>>s>>f;
    int l[q],r[q];
    fo(i,q){
        // l[i]=1;r[i]=n;
        cin>>l[i]>>r[i];
        l[i]--; r[i]--;
        // deb2(l[i],r[i]);
    }
    
    fo(i,n){
        a[i]=f[i]-'0';
        b[i]=s[i]-'0';
    }
    
    fo(i,4*n){
        tree[i]=0;
        lazy[i]=-1;
    }
    // fo(i,n){
    //     cout<<a[i];
    // }cout<<nl;
    build(1,0,n-1);
    // fo(i,n){
    //     cout<<query(1,i,i,0,n-1);
    // }cout<<nl;
    
    for(i=q-1;i>=0;i--){
        int left,right,len,one,zero;
        left=l[i];
        right=r[i];
        // deb2(left,right);
        len=right-left+1;
        one=query(1,left,right,0,n-1);
        zero=len-one;
        // deb2(one,zero);
        if(one>zero){
            update(1,left,right,0,n-1,1);
        }
        else if(zero>one){
            update(1,left,right,0,n-1,0);
        }
        else{
            cout<<"NO\n";
            return;
        }
        
    }
    // fo(i,n){
    //     cout<<a[i]<<" ";
    // }cout<<endl;
    fo(i,n){
        if(b[i]==query(1,i,i,0,n-1)){
            continue;
        }
        // deb(i);
        // cout<<query(1,i,i,0,n-1);
        cout<<"NO\n";
        return;
    }


    cout<<"YES\n";
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

