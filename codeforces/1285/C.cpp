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
lli gcd(lli a,lli b)
{   if(b==0)
        return a;
    return gcd(b,a%b);    
}
lli lcm(lli a,lli b)
{   return (a*b)/(gcd(a,b));

}

void solve()
{   lli i,j;
    lli x,ans; 
    cin>>x; //deb(x);
   
    for(i=1;i*i<=x;i++)
    {   if(x%i==0 && lcm(i,x/i)==x)
            ans=i;
    } 
    cout<<ans<<" "<<x/ans<<endl;   
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