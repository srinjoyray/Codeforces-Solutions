#include <bits/stdc++.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<ctype.h>
#define lli long long int 
#define mod 1000000007
using namespace std;
#define pi 3.141592653589793238

int main()
{ int n;
  cin>>n;
  int a[n],g[n],sum_a=0,sum_g=0;
  for(int i=0;i<n;i++)
     cin>>a[i]>>g[i]; 
  for(int i=0;i<n;i++)
  { if(sum_a==sum_g)
      { if(a[i]<=g[i])
         {cout<<"A";sum_a+=a[i];}
        else
         {cout<<"G";sum_g+=g[i];}
      }
    else if(sum_a<sum_g)
      { if((sum_g+g[i])-(sum_a)<=500)
            {cout<<"G";sum_g+=g[i];}
        else 
            {cout<<"A";sum_a+=a[i];}
      }
    else
      { if((sum_a+a[i])-(sum_g)<=500)
            {cout<<"A";sum_a+=a[i];}
        else 
            {cout<<"G";sum_g+=g[i];}
      }
      
  }
  return 0;  
}