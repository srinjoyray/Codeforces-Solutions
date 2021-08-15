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
string s;
struct node{
    int current,open,close;
};
node tree[4*N];

void build_tree(int start,int end,int index){
    

    if(start==end){
        tree[index].current=0;
        tree[index].open=s[start]=='(';
        tree[index].close=s[start]==')';
        // deb(start);
        // cout<<tree[index].open<<"   "<<tree[index].close<<nl;
        return;
    }
    int mid = (start+end)/2;
    build_tree(start,mid,2*index);
    build_tree(mid+1,end,2*index+1);

    int add = min(tree[2*index].open,tree[2*index+1].close);
    tree[index].current=tree[2*index].current+tree[2*index+1].current+add;
    tree[index].close=tree[2*index].close+tree[2*index+1].close-add;
    tree[index].open=tree[2*index].open+tree[2*index+1].open-add;
    // deb(index);
    // deb2(start,end);
    // deb2(index,tree[index].current);
    // cout<<tree[index].open<<"   "<<tree[index].close<<nl;
}
node query(int start,int end,int index,int left,int right){
    if(start>right || end<left){
        return{0,0,0};
    }
    if(start>=left && end <=right)
        return tree[index];

    int mid=(start+end)/2;

    node left_node,right_node,curr_node;
    left_node=query(start,mid,2*index,left,right);
    right_node=query(mid+1,end,2*index+1,left,right);

    int add = min(left_node.open,right_node.close);
    curr_node.current=left_node.current+right_node.current+add;
    curr_node.open=left_node.open+right_node.open-add;
    curr_node.close=left_node.close+right_node.close-add;

    return curr_node;
}
void solve(){
    int i,j;
    cin>>s;
    int n,q;
    n=s.size();
    cin>>q;
    build_tree(0, n - 1, 1);
    while(q--){
        int l,r,ans;
        cin>>l>>r;
        // deb2(l,r);
        l--; r--;
        ans=query(0,n-1,1,l,r).current;
        cout<<ans*2<<nl;
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

