#include <bits/stdc++.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<ctype.h>
#define lli long long int 
#define mod 1000003
#define pi 3.141592653589793238
using namespace std;
 
int main()
{ int t;
  cin>>t;
  while(t--)
  { int n;
    cin>>n;
    lli a[n],sum=0,b[n],sum1=0,sum2=0;
    for(int i=0;i<n;i++)
      { cin>>a[i];
        sum+=a[i];
      }
    for(int i=0;i<n;i++)
      b[i]=a[i];
    
    for(int i=0;i<n;i++)
       if(i%2==0)
         sum1+=b[i];
       else
         sum2+=b[i];  
    if(sum1<=sum2)
      for(int i=0;i<n;i+=2)
          b[i]=1;
    else      
      for(int i=1;i<n;i+=2)
          b[i]=1;
    for(int i=0;i<n;i++)    
      cout<<b[i]<<" ";
    cout<<endl;  
  }
  return 0;  
}