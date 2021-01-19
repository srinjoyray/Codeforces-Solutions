#include <bits/stdc++.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<ctype.h>
#define lli long long int 
#define mod 1000000007
#define pi 3.141592653589793238
using namespace std;
bool prime(lli n)
{ 
 for(int i=2;i<=sqrt(n);i++)
   if(n%i==0)
      return false;
  return true;
    
}

int main()
{   int t;
    cin>>t;
    //t=1; 
    while(t--)
    { lli d,ans,a,b,temp;
      cin>>d;
      a=1+d;
      while(prime(a)==false)
       a++;
      b=a+d;
      while(prime(b)==false)
       b++;
       
      ans=a*b;
      
      cout<<ans<<endl;
      
    }  
    
    return 0;  
}