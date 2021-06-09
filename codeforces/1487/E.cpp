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
const int inf=1e9;
void input_dish(vpii &v,int n){
    int i,temp;
    fo(i,n){
        cin>>temp;
        v[i]={temp,i};
    }
    sort(all(v));
}
void input_edge(int m,map<pii,int> &edge){
    int i,x,y;
    fo(i,m){
        cin>>x>>y;
        x--;
        y--;
        edge[{x,y}]=1;
    }
}

void func(vpii &a,vpii b,map<pii,int> edge,int n1,int n2){
    int i,j;
    fo(i,n1){
        fo(j,n2){
            if(edge[{a[i].S,b[j].S}]==0){
                a[i].F+=b[j].F;
                break;
            }
            else if(j==n2-1){
                a[i].F=inf;
            }
        }
    }
    sort(all(a));
    /*fo(i,n1){
        cout<<a[i].F<<"#"<<a[i].S<<" ";
    }cout<<nl;*/
}
void solve(){
    int i,j;
    int n1,n2,n3,n4;
    cin>>n1>>n2>>n3>>n4;
    vpii a(n1),b(n2),c(n3),d(n4);

    input_dish(a,n1);
    input_dish(b,n2);
    input_dish(c,n3);
    input_dish(d,n4);

    int m1,m2,m3;
    map<pii,int> edge[3];
    cin>>m1;
    input_edge(m1,edge[0]);
    cin>>m2;
    input_edge(m2,edge[1]);
    cin>>m3;
    input_edge(m3,edge[2]);

    func(c,d,edge[2],n3,n4);
    func(b,c,edge[1],n2,n3);
    func(a,b,edge[0],n1,n2);

    int mn=inf;
    fo(i,n1){
        mn=min(mn,a[i].F);
    }
    if(mn>=inf){
        mn=-1;
    }
    cout<<mn<<nl;
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

