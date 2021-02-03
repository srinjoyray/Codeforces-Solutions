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

lli power(lli base,lli exp);
lli mpower(lli base,lli exp,lli m);
lli gcd(lli a,lli b);
lli lcm(lli a,lli b);

void solve()
{   int i,j;
    int n;
    cin>>n;
    int a[n],count=0,ans=0,temp[n+1]={0};
    fo(i,n) 
    {   cin>>a[i];
    }
    sort(a,a+n);
    fo(i,n)
    {   if(temp[a[i]]==0)   
        {   temp[a[i]]++;
            continue;
        }    
        else
        {   fo2(j,a[i]+1,n)
            {   if(temp[j]==0)
                {   ans+=j-a[i];
                    temp[j]=1;
                    // deb(i);deb(j);
                    break;
                }    
                else if(j==n)
                {   ans+=n-a[i];
                    count++;
                }
            }
            if(a[i]==n)
                count++;
        }
    //    deb(i);
        // deb(ans);
    }
    ans+=(count*(count+1))/2;
    cout<<ans<<endl;
}

int main()
{   ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}

lli power(lli base,lli exp)
{
    lli result=1;
    while(exp)
    {   if(exp%2==1)
            result*=base;
        base=base*base;
        exp/=2;
    }
    return result;
}

lli mpower(lli base,lli exp,lli m)
{   base%=m;   
    lli result=1;
    while(exp)
    {   if(exp%2==1)
            result=(result*base)%m;
        base=(base*base)%m;
        exp/=2;    
    }
    return result;
}

lli gcd(lli a,lli b)
{   if(b==0)
        return a;
    return gcd(b,a%b);    
}

lli lcm(lli a,lli b)
{
    return (a*b)/gcd(a,b);
}