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
lli fact[1000000];
lli power(lli a,lli n){
    lli res=1;
    while(n){
        if(n%2==1){
            res*=a;
            res%=mod;
            n--;
        }
        else{
            a*=a;
            a%=mod;
            n/=2;
        }
    }
    return res%=mod;
}
lli npr(lli n,lli r){
    lli num,denom,ans;
    num=fact[n];
    denom=fact[n-r];
    denom=power(denom,mod-2);
    ans=(num*denom)%mod;
    return ans;
}
void solve(){
    int i,j;
    int n;
    cin>>n;
    lli a[n],ans,temp,andd,count=0,rem;
    fo(i,n){
        cin>>a[i];
        
    }
    andd=a[0];
    fo(i,n){
        andd=andd & a[i];
    }
    
    fo(i,n){
        if(a[i]==andd){
            count++;
        }
    }
    if(count<2){
        cout<<"0\n";
        return;
    }
    else{
        temp=npr(count,2);
        rem=n-2;
        ans=(temp*fact[rem])%mod;
        cout<<ans<<nl;
    }

    /*vector<pair<lli,lli>> freq;
    vector<lli> single;
    fo(i,n){
        j=i+1;
        while(j<n && a[j]==a[i]){
            j++;
        }
        temp=j-i;
        i=j-1;
        if(temp>1){
            freq.pb({a[i],temp});
        }
        else{
            single.pb(a[i]);
        }
    }
    if(freq.size()==0){
        cout<<"0\n";
        return;
    }*/

}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t=1;
    cin>>t;
    fact[0]=1;
    fact[1]=1;
    for(lli i=1;i<=1000000;i++){
        fact[i]=(i*fact[i-1])%mod;
    }
    while(t--){
        solve();
    }
    return 0;
}

