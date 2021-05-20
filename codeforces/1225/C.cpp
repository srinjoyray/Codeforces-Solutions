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
    lli n,p,count=0,temp,rem;
    cin>>n>>p;
    bool flag=false;
    if(p<0){
        temp=abs(p);
        while(temp>1){
            if(temp%2!=0){
                break;
            }
            temp/=2;
        }
        if(temp==1){
            flag=true;
        }
    }
    i=1;
    while(i<=100000){
        temp=n-(i*p);
        count=0;
        if(temp<i){
            i++;
            continue;
        }
        if(i==2){
            // deb(temp);
        }
        // deb(temp);
        while(temp){
            rem=temp%2;
            if(rem){
                count++;
            }
            temp/=2;
        }
        if(count<=i || (count<=i && flag)){
            cout<<i<<nl;
            return;
        }
        i++;
    }
    cout<<"-1\n";
    
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

