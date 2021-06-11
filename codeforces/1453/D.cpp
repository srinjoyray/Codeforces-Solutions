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
ll store[3000];
void init(){
    for(int i=1;i<=60;i++){
        store[i]=2+2*store[i-1];
    }
}
void solve(){
    int i,j;
    ll k;
    cin>>k;
    if(k%2==1){
        cout<<"-1\n";
        return ;
    }
    string s;
    ll temp,z=5;
    
    while(k){
        // deb(k);
        for(i=1;i<=60;i++){
            if(store[i]>k){
                temp=store[i-1];
                fo(j,i-1){
                    if(j==0){
                        s.pb('1');
                    }
                    else{
                        s.pb('0');
                    }
                }
                k-=temp;
                break;
            }
        }
    }

    cout<<s.size()<<nl;
    fo(i,s.size()){
        cout<<s[i]<<" ";
    }cout<<nl;
    
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t=1;
    cin>>t;
    init();
    while(t--){
        solve();
    }
}

