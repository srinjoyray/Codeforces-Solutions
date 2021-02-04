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
#define tr(it,a) for(auto it=a.begin(); it!=a.end();it++)
#define PI 3.141592653589793238
#define mod 1e9+7

void solve()
{   int i,j;
    int n;
    cin>>n;
    lli a[n],hcf=0,count=0;
    fo(i,n) cin>>a[i];
    fo(i,n) hcf=__gcd(hcf,a[i]);
    // deb(hcf);
      
    for(i=1;i*1ll*i<=hcf;i++)
    {   if(hcf%i==0)
        {   count++;
            if(i != hcf/i)
                count++;   
        }
    }
    cout<<count<<endl;
}

int main()
{   ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}

