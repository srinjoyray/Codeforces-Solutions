#include <bits/stdc++.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<ctype.h>
using namespace std;
 
int main()
{ int n;
  cin>>n;
  int a[n],one=0,sum=0,max_sum=-1;
  for(int i=0;i<n;i++)
    {  cin>>a[i];
       if(a[i]==1)
          one++;
       if(a[i]==0)
          a[i]=1;
       else if(a[i]==1)
          a[i]=-1;
       
    }
    
   for(int i=0;i<n;i++)        
     {  sum+=a[i];
        
        max_sum=std::max(max_sum,sum);
        if(sum<0)
         sum=0;
     }   
      
   cout<<max_sum+one;
  return 0;  
}