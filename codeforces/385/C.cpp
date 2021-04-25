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
#define MAXN 10000001
lli spf[MAXN+1]; 
void sieve()
{
    spf[1] = 1;
    for (lli i=2; i<MAXN; i++)
  
        // marking smallest prime factor for every
        // number to be itself.
        spf[i] = i;
  
    // separately marking spf for every even
    // number as 2
    for (lli i=4; i<MAXN; i+=2)
        spf[i] = 2;
  
    for (lli i=3; i*i<MAXN; i++)
    {
        // checking if i is prime
        if (spf[i] == i)
        {
            // marking SPF for all numbers divisible by i
            for (lli j=i*i; j<MAXN; j+=i)
  
                // marking spf[j] if it is not 
                // previously marked
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}
void solve(){
    lli i,j;
    lli n,m;
    sieve();
    cin>>n;
    // deb(n);
    lli a[n],l,r,temp,val,sum=0,ans;
    map<lli,lli> mapp,pref;
    vector<lli> v;
    vector<lli>::iterator pos1,pos2;
    bool flag;
    fo(i,n){
        cin>>a[i];
    }
    fo(j,n){
        temp=a[j];
        // deb(temp);
        while(temp>1){
            val=spf[temp];
            // deb(val);
            mapp[val]++;
            while(temp%val==0){
                temp/=val;
            }
        }
    }
    tr(it,mapp){
        temp=(*it).F;
        v.pb(temp);
        sum+=(*it).S;
        pref[temp]=sum;
    }
    cin>>m;
    fo(i,v.size()){
        // cout<<v[i]<<" "<<mapp[v[i]]<<nl;
    }
    fo(i,m){
        cin>>l>>r;
        // deb2(l,r);
        if(l>v[v.size()-1] || r<v[0]){
            cout<<"0\n";
            continue;
        }
        pos1=lower_bound(all(v),l);
        pos2=upper_bound(all(v),r);
        l=v[pos1-v.begin()];
        r=v[pos2-v.begin()-1];
        // deb2(l,r);
        ans=pref[r]-pref[l]+mapp[l];
        cout<<ans<<nl;
    }
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

