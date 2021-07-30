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
bool check(ll a[],ll n,ll b[],ll m){
    int i=0,j=0,i1,j1;
    while(i<n && j<m){
        i1=i;
        while(i1<n && a[i1]!=b[j]){
            i1++;
        }
        if(i1<n){
            j++;
        }
        i=i1+1;
    }
    if(j==m){
        return false;
    }
    return true;
}
void solve(){
    int i,j,i1,j1;
    ll n,m;
    cin>>n>>m;
    ll x,k,y,cost=0;
    cin>>x>>k>>y;
    ll a[n],b[m],mx,len,p,q,rem,temp;
    fo(i,n){
        cin>>a[i];
    }
    fo(i,m){
        cin>>b[i];
    }
    if(check(a,n,b,m)){
        cout<<"-1\n";
        return;
    }
    i=0;j=0;
    
    while(i<n && j<m){
        i1=i;
        // deb2(i,j);
        while(i1<n && a[i1]!=b[j]){
            // deb2(a[i1],b[j]);
            i1++;            
        }
        // deb2(i,i1);
        mx=0;
        for(j1=i;j1<=i1-1;j1++){
            mx=max(mx,a[j1]);
        }
        len=i1-i;
        if(len==0){
            i=i1+1;
            j++;
            // deb2(i1,j);
            continue;
        }
        // deb(len);
        p=-1; q=-1;
        if(i>0){
            p=a[i-1];
        }
        q=a[i1];
        if(len<k){
            if(mx>p && mx>q){
                cout<<"-1\n";
                return;
            }
            cost+=y*len;
        }
        else{
            rem=len%k;
            len-=len%k;
            cost+=y*rem;
            if(mx>p && mx>q){
                len-=k;
                cost+=x;
                if(x<=y*k){
                    temp=len/k;
                    cost+=temp*x;
                }
                else{
                    cost+=len*y;
                }
            }
            else{
                if(x<=y*k){
                    temp=len/k;
                    cost+=temp*x;
                }
                else{
                    cost+=len*y;
                }
            }
        }
        i=i1+1;
        j++;
    }
    len=n-i;
    // deb(len);
    if(len==0){
        cout<<cost<<nl;
        return;
    }
    p=a[i-1]; q=-1;
    mx=0;
    for(j1=i;j1<n;j1++){
        mx=max(mx,a[j1]);
    }
    if(len<k){
        if(mx>p && mx>q){
            cout<<"-1\n";
            return;
        }
        cost+=y*len;
    }
    else{
        rem=len%k;
        len-=len%k;
        cost+=y*rem;
        if(mx>p){
            len-=k;
            cost+=x;
            if(x<=y*k){
                temp=len/k;
                cost+=temp*x;
            }
            else{
                cost+=len*y;
            }
        }
        else{
            if(x<=y*k){
                temp=len/k;
                cost+=temp*x;
            }
            else{
                cost+=len*y;
            }
        }
    }


    cout<<cost<<nl;
    
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

