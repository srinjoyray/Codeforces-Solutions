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
lli gcd(lli a, lli b)
{ if(b==0)
    return a;
  return gcd(b,a%b);    
}
int main()
{   int t;
    cin>>t;
    //t=1; 
    while(t--)
    { int n;
      cin>>n;
      lli a[n],temp[n],min,flag=0;
      for(int i=0;i<n;i++)
        { cin>>a[i];
          temp[i]=a[i];
        }  
      sort(temp,temp+n);
      min=temp[0];
      /*for(int i=0;i<n;i++)
        cout<<temp[i]<<" ";
      cout<<endl; */  
      for(int i=0;i<n;i++)
      { 
        if(a[i]==temp[i])
          continue;
        else 
         { if(a[i]%min==0)
             { 
                 continue;
             }     
           else
            {flag=1;break;}
         }
         
      }
      if(flag==1)
        cout<<"NO\n";
      else
        cout<<"YES\n";
    }  
    
    return 0;  
}