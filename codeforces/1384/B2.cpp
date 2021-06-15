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
    int n,k,l;
    cin>>n>>k>>l;
    int d[n],dir,ht[n],h;
    fo(i,n){
        cin>>d[i];
    }
    fo(i,n){
        if(d[i]>l){
            cout<<"No\n";
            return;
        }
        ht[i]=min(k,l-d[i]);
    }
    // fo(i,n){
    //     cout<<ht[i]<<" ";
    // }cout<<nl;
    dir=-1;h=l+1;
    fo(i,n){
        // deb2(dir,h);
        // deb(ht[i]);
        if(ht[i]==k){
            dir=-1;
            h=k;
            continue;
        }
        if(dir==1){
            if(ht[i]<=h){
                cout<<"No\n";
                return;
            }
            h++;
        }
        if(dir==-1){
            if(ht[i]<h){
                h=ht[i];
            }
            else{
                h--;
            }
            if(h==0){
                dir=1;
            }
        }


    }

    cout<<"Yes\n";
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

