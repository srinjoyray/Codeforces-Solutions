#include <bits/stdc++.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<ctype.h>
using namespace std;
 
int main()
{ int T;
  cin>>T;
  while(T--)
  { int n;
    cin>>n;
    long long int a[n],max;
    long long int sum=0,temp1,temp2,temp;
    for(int i=0;i<n;i++)
       { cin>>a[i];
         sum+=a[i];
       }
    max=a[0]; 
    for(int i=1;i<n;i++)
      { if(a[i]>max)
          max=a[i];
      }      
    if(sum%(n-1)!=0)
       temp1=sum+(n-1)-sum%(n-1);
    else 
       temp1=sum;
    temp2=max*(n-1);
    
    temp=std::max(temp1,temp2);
    
    cout<<temp-sum<<endl;
   
  }
  return 0;  
}