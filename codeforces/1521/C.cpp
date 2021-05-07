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
    int n,x,input;
    cin>>n;
    // deb(n);
    int a[n],pos=-1;
    bool flag=false;
    x=n-1;
    for(i=0;i<n-1;i+=2){
        
        cout<<"? 1 "<<i+1<<" "<<i+2<<" "<<x<<endl;
        cin>>input;
        // deb(input);
        if(input==n){
            a[i+1]=n;
            pos=i+1;
            // deb(pos);
            break;
        }
        if(input==n-1){
            cout<<"? 1 "<<i+2<<" "<<i+1<<" "<<x<<endl;
            cin>>input;
            if(input==n){
                a[i]=n;
                pos=i;
                break;
            }
        }
    }
    // deb(pos);
    if(pos==-1 && n%2==1){
        pos=n-1;
        a[pos]=n;
    }
    x=1;
    fo(i,n){
        if(i==pos){
            continue;
        }
        cout<<"? 2 "<<i+1<<" "<<pos+1<<" "<<x<<endl;
        cin>>input;
        a[i]=input;
    }
    cout<<"! ";
    fo(i,n){
        cout<<a[i]<<" ";
    }cout<<endl;
    
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
    return 0;
}

