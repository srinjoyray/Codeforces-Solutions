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
    int i,j,index;
    int n,mx;
    cin>>n;
    int a[n],input1,input2;
    index=0;mx=1;
    memset(a,-1,sizeof(a));
    if(n==1){
        cout<<"! 1"<<endl;
        return;
    }
    cout<<"? "<<1<<" "<<2<<endl;
    cin>>input1;
    cout<<"? "<<2<<" "<<1<<endl;
    cin>>input2;
    if(input1>input2){
        a[0]=input1;
        index=1;
    }
    else{
        a[1]=input2;
        index=0;
    }

    fo2(i,2,n-1){
        cout<<"? "<<i+1<<" "<<index+1<<endl;
        cin>>input1;
        cout<<"? "<<index+1<<" "<<i+1<<endl;
        cin>>input2;

        if(input1>input2){
            a[i]=input1;
        }
        else{
            a[index]=input2;
            index=i;
        }
    }
    fo(i,n){
        if(a[i]==-1){
            a[i]=n;
            break;
        }
    }
    cout<<"! ";
    fo(i,n){
        cout<<a[i]<<" ";
    }cout<<nl;
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
    return 0;
}

