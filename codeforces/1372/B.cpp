#include <bits/stdc++.h>
#define lli long long int 
#define mod 1000000007
#define pi 3.141592653589793238
using namespace std;
lli gcd(lli a, lli b)
{   if(b==0) 
        return a;
    return gcd(b,a%b);    
}
lli lcm(lli a, lli b)
{
    return (a*b)/gcd(a,b);
}
int main()
{   int t=1;
    cin>>t;
    while(t--)
    {   lli n,temp;
        cin>>n;
        
        if(n%2==0)
        { cout<<n/2<<" "<<n/2<<endl;
          continue;    
        } 
        for(int i=2;i*i<=n;i++)
        {   if(n%i==0)
            {   temp=n/i;
                cout<<n-temp<<" "<<temp<<endl;   
                break;
            }
            else if((i+1)*(i+1)>n)
                cout<<1<<" "<<n-1<<endl;
        }
        
    }  
    
    return 0;  
}