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
void print(int n,int pos){
    if(pos!=-1){
        cout<<"2 "<<pos<<nl;
    }
    int curr;
    curr=(pos==1 ? 2:1);
    for(int i=curr+1;i<=n;i++){
        if(i==pos){
            continue;
        }
        cout<<"1 "<<curr<<" "<<i<<nl;
        curr=i;
    }
}
void solve(){
    int i,j;
    int n;
    cin>>n;
    ll a[n],neg=0,zero=0,curr;
    vpl v1,v2;
    set<int> se;
    fo(i,n){
        cin>>a[i];
    }
    fo(i,n){
        if(a[i]<0){
            neg++;
            v1.pb({a[i],i+1});
        }
        if(a[i]==0){
            zero++;
            v2.pb({a[i],i+1});
        }
        else{
            se.insert(i+1);
        }
    }
    sort(all(v1));
    sort(all(v2));
    if(neg%2==1 && zero==0){
        print(n,v1[v1.size()-1].S);
    }
    else{
        if(zero==0 || se.size()==0){
            print(n,-1);
        }
        else{
            curr=v2[0].S;
            for(i=1;i<v2.size();i++){
                cout<<"1 "<<curr<<" "<<v2[i].S<<nl;
                curr=v2[i].S;
            }
            if(neg%2==1){
                cout<<"1 "<<curr<<" "<<v1[v1.size()-1].S<<nl;
                curr=v1[v1.size()-1].S;
                se.erase(v1[v1.size()-1].S);
            }
            if(se.size()==0){
                return;
            }
            cout<<"2 "<<curr<<nl;
            
            curr=*se.begin();
            se.erase(se.begin());
            while(se.size()){
                cout<<"1 "<<curr<<" "<<*se.begin()<<nl;
                curr=*se.begin();
                se.erase(se.begin());
            }
        }
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

