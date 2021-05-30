#include<bits/stdc++.h>
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define fo2(i,start,end) for(i=start;i<=end;i++)
#define rfo(i,n) for(i=n-1;i>=0;i--)
#define lli long long int
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
typedef pair<lli, lli>	pl;
typedef vector<int>		vi;
typedef vector<lli>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
void solve(){
    int i,j,mid;
    int n,m;
    cin>>n>>m;
    ll a[n],x,sum=0,pref[n],mx,count=0;
    fo(i,n){
        cin>>a[i];
    }
    fo(i,n){
        sum+=a[i];
        if(i>0 && pref[i-1]>sum){
            pref[i]=pref[i-1];
        }
        else{
            pref[i]=sum;
        }
    }
    mx=pref[n-1];
    ll diff;
    while(m--){
        cin>>x;
        count=0;
        if(x>mx){
            if(sum<=0){
                cout<<"-1 ";
                continue;
            }
            diff=x-mx;
            count=(diff+sum-1)/sum;
            x=x-sum*count;
            count*=n;
        }
        i=0; j=n-1;
        // deb2(x,count);
        count +=lower_bound(pref,pref+n,x)-pref;
        /*while(i<=j){
            // deb2(i,j);
            if(i==j){
                count+=i;
                break;
            }
            mid=(i+j)/2;
            if(pref[mid]<x){
                i=mid+1;
            }
            else if(pref[mid]>=x){
                j=mid;
            }
        }*/
        cout<<count<<" ";
    }cout<<nl;
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

