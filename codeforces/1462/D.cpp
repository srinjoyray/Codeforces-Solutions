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
    int arr[n],sum=0,each_sum,sub_sum,flag=0;
    for(int i=0;i<n;i++)
       cin>>arr[i];
    for(int i=0;i<n;i++)
       sum+=arr[i];
    for(int i=0;i<n;i++)
    { each_sum=sum/(n-i);
      if(each_sum*(n-i)!=sum)
         continue;
      sub_sum=0; flag=0;     
      for(int j=0;j<n;j++)
        { sub_sum+=arr[j];
          if(sub_sum>each_sum)
            {flag=1;break;}
          else if(sub_sum==each_sum)
            sub_sum=0;
        } 
      if(flag==0)
        {cout<<i<<endl; break;}
    }
      
  }
  return 0;  
}