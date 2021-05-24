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
    lli i,j;
    lli n;
    cin>>n;
    lli a[n],count=0,diff,mn,temp,last;
    fo(i,n){
        cin>>a[i];
    }
    sort(a,a+n);
    vl v;
    fo(i,n){
        if(a[i]<=0){
            v.pb(a[i]);
        }
    }
    // last=v[v.size()-1];
    if(v.size()>=2){
        diff=abs(v[1]-v[0]);
        mn=diff;
        for(i=2;i<v.size();i++){
            temp=abs(v[i]-v[i-1]);
            mn=min(mn,temp);
        }
        // deb(mn);
        count=v.size();
        fo(i,n){
            if(a[i]>0 && a[i]<=mn ){
                count++;
                break;
            }
        }
        cout<<count<<nl;
        return;
    }
    else{
        temp=v.size()+1;
        count=min(temp,n);
        cout<<count<<nl;
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

