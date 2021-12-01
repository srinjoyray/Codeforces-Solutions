#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fo(i,n) for(i=0;i<n;i++)
#define fo2(i,start,end) for(i=start;i<=end;i++)
#define rfo(i,n) for(i=n-1;i>=0;i--)
#define deb(x) cout<<#x<<"="<<x<<endl
#define deb2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
#define ll long long
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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

const int N=1e6+10;
int dig(int num){
    int ans=0;
    while(num){
        num/=10;
        ans++;
    }
    return ans;
}
void solve(){
    int i,j;
    int x1,p1,x2,p2;
    cin>>x1>>p1>>x2>>p2;
    if(dig(x1)+p1<dig(x2)+p2){
        cout<<"<\n";
        return;
    }
    if(dig(x1)+p1>dig(x2)+p2){
        cout<<">\n";
        return;
    }

    while(dig(x1)<dig(x2)){
        x1*=10;
    }
    while(dig(x2)<dig(x1)){
        x2*=10;
    }
    if(x1>x2){
        cout<<">\n";
    }
    else if(x1<x2){
        cout<<"<\n";
    }
    else{
        cout<<"=\n";
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
    
}

