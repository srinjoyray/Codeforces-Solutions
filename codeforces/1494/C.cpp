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
ll func(vl a, vl b){
    ll n,m,ans=0,i,j,count;
    n=a.size();
    m=b.size();
    if(n==0 || m==0){
        return 0;
    }
    set<ll> seA,seB;
    fo(i,n){
        seA.insert(a[i]);
    }
    fo(i,m){
        seB.insert(b[i]);
    }
    map<ll,ll>mapA,mapB;
    fo(i,n){
        mapA[a[i]]=i+1;
    }
    fo(i,m){
        mapB[b[i]]=i+1;
    }
    
    ll val,nos,l=0,r,initial=0;
    fo(i,m){
        if(mapA[b[i]]>0){
            initial++;
        }
    }
    fo(i,m){
        r=b[i];
        // deb(r);
        if(mapA[b[i]]>0){
            initial--;
        }
        if(*seA.begin()>r){
            continue;
        }
        nos=mapA[*(--seA.upper_bound(r))];
        l=r-nos+1;
        // deb2(l,nos);
        if(*seB.begin()>=l){
            count=mapB[r];
        }
        else{
            l=*(--seB.lower_bound(l));
            count=mapB[r]-mapB[l];
            // deb2(l,r);
            // deb2(mapB[l],mapB[r]);
        }
        // deb(count);
        count+=initial;
        ans=max(ans,count);
    }
    return ans;
}
void solve(){
    int i,j;
    int n,m;
    cin>>n>>m;
    ll temp,ans;
    vl a1,a2,b1,b2;
    fo(i,n){
        cin>>temp;
        if(temp>=0){
            a1.pb(temp);
        }
        else{
            a2.pb(abs(temp));
        }
    }
    fo(i,m){
        cin>>temp;
        if(temp>=0){
            b1.pb(temp);
        }
        else{
            b2.pb(abs(temp));
        }
    }

    sort(all(a1));
    sort(all(b1));
    sort(all(a2));
    sort(all(b2));

    ans=func(a1,b1)+func(a2,b2);

    cout<<ans<<nl;
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

