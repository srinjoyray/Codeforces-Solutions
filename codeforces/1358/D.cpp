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
    ll n,x;
    cin>>n>>x;
    ll a[n],curr,sum,val;
    fo(i,n){
        cin>>a[i];
    }
    set<ll> se;
    map<ll,ll> mapp;
    ll b[n],pref[n+1]={0};
    curr=0;
    fo(i,n){
        curr+=a[i];
        se.insert(curr);
        mapp[curr]=i;
        // deb2(curr,i);
    }
    sum=curr;
    fo(i,n){
        b[i]=a[i]*(a[i]+1)/2;
        pref[i+1]=pref[i]+b[i];
    }
    // fo(i,n){
    //     cout<<b[i]<<" ";
    // }cout<<nl;
    // fo(i,n+1){
    //     cout<<pref[i]<<" ";
    // }cout<<nl;
    curr=0;
    ll mx=0,temp,rem,add,del;
    fo(i,n){
        curr+=a[i];
        ll pos,ub;
        // deb2(curr,x);
        if(curr>=x){
            val=curr-x;
            ub=*se.upper_bound(val);
            pos=mapp[ub];
            // deb2(pos,ub);
            // deb(val);

            
            rem=ub-val;
            add=a[pos]*(a[pos]+1)/2;
            del=a[pos]-rem;
            del=del*(del+1)/2;
            add-=del;

            if(i==n-1){
                // deb2(pos,ub);
                // deb(val);
                // deb2(rem,add);
                // deb2(i,pos);
                // temp=pref[i+1]-pref[pos+1];
                // deb(temp);
            }
            // deb2(rem,add);
            // deb2(i,pos);
            temp=pref[i+1]-pref[pos+1]+add;
        }
        else{
            val=sum-(x-curr);
            // deb(val);
            if(se.upper_bound(val)==se.end()){
            
                pos=n-1;

                rem=a[pos]-(x-curr);
                add=a[pos]*(a[pos]+1)/2;
                del=a[pos]-rem;
                del=del*(del+1)/2;
                add-=del;

                temp=pref[i+1]+add;
            }
            else{
                ub=*se.upper_bound(val);
                pos=mapp[ub];

                rem=ub-val;
                add=a[pos]*(a[pos]+1)/2;
                del=a[pos]-rem;
                del=del*(del+1)/2;
                add-=del;
                if(i==0){
                    // deb2(pos,ub);
                    // deb(val);
                    // deb2(rem,add);
                    // deb2(i,pos);
                    // temp=pref[i+1]+pref[n]-pref[pos+1];
                    // deb(temp);
                }
                temp=pref[i+1]+pref[n]-pref[pos+1]+add;
            }
        }
        // deb(temp);
        mx=max(mx,temp);
    }
    cout<<mx<<nl;
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

