#include<bits/stdc++.h>
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define fo2(i,start,end) for(i=start;i<=end;i++)
#define rfo(i,n) for(i=n-1;i>=0;i--)
#define lli long long int
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
typedef pair<lli, lli>	pl;
typedef vector<int>		vi;
typedef vector<lli>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
void solve(){
    int i,j;
    int n;
    cin>>n;
    int t[n],val=1,pos=-1;
    fo(i,n){
        cin>>t[i];
    }
    fo(i,n-1){
        if(t[i]!=t[i+1]){
            break;
        }
        if(i==n-2){
            cout<<"1\n";
            fo(j,n){
                cout<<"1 ";
            }cout<<nl;
            return;
        }
    }
    if(n%2==0){
        cout<<"2\n";
        fo(i,n){
            cout<<i%2+1<<" ";
        }
        cout<<nl;
        return;
    }
    bool flag=false;
    fo(i,n-1){
        if(t[i]==t[i+1]){
            pos=i;
            flag=true;
            break;
        }
    }
    if(t[0]==t[n-1]){
        flag=true;
    }
    if(!flag){
        cout<<"3\n";
        fo(i,n){
            if(i==n-1){
                cout<<"3 ";
            }
            else{
                cout<<i%2+1<<" ";
            }
        }
        cout<<nl;
        return;
    }
    cout<<"2\n";
    fo(i,n){
        cout<<val<<" ";
        if(i==pos){
            i++;
            cout<<val<<" ";
        }
        if(val==1){
            val=2;
        }
        else{
            val=1;
        }
    }
    cout<<nl;
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

