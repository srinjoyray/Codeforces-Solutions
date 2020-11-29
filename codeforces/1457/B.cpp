#include <bits/stdc++.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<ctype.h>
using namespace std;
 
int main()
{ int t;
  cin>>t;
  while(t--)
  { int n,k,min;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
       cin>>arr[i];
    min=(n+k-1)/k;   
    
    int start,end;
    start=arr[0]; end=arr[0];
    for(int i=0;i<n;i++)
       if(arr[i]>end)
          end=arr[i];
       else if(arr[i]<start)
          start=arr[i];
          
    for(int j=start;j<=end;j++)
      { int count=0;
        for(int i=0;i<n;i++)
           if(arr[i]==j)
             continue;
           else
            { count++; i+=k-1;}
        min=std::min(min,count);    
      }
    cout<<min<<endl;  
  }
  return 0;  
}