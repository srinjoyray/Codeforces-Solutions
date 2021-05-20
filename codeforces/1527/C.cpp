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
    lli a[n],ans=0,temp,rem,val;
    fo(i,n){
        cin>>a[i];
    }
    map<lli,vl> freq;
    map<lli,lli> sum,mapp;
    fo(i,n){
        freq[a[i]].pb(i+1);
        mapp[a[i]]++;
        /*ans+=ans;
        // deb2(a[i],mapp[a[i]]);
        // if(mapp[a[i]]>1){
        //     // deb(ans);
        //     ans-=mapp[a[i]];
        //     // deb(ans);
        // }
        
        if(freq[a[i]].size()==1){
            sum[a[i]]+=i+1;
            continue;
        }
        temp=sum[a[i]];
        ans+=(temp);
        sum[a[i]]+=i+1;
        deb2(i,ans);
        */
    }
    lli count,l,r;
    for(auto x:mapp){
        if(x.S<=1){
            continue;
        }
        val=x.F;
        count=0;
        // deb(val);
        fo(i,freq[val].size()){
            // deb(freq[val][i]);
            if(i==0){
                count+=freq[val][0];
                continue;
            }
            l=count;
            r=n-freq[val][i]+1;
            // deb2(l,r);
            temp=l*r;
            // deb2(i,temp);
            ans+=temp;
            count+=freq[val][i];
        }
    }
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
    return 0;
}

