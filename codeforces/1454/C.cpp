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
  { int n;
    cin>>n;
    int arr[n],count[n+1]={0},min=n;
    for(int i=0;i<n;i++)
       cin>>arr[i];
    for(int i=0,j;i<n;i++)
      {  count[arr[i]]++;
         j=i+1;
         while(arr[j]==arr[i] && j<n)
            j++;
         i=j-1;    
      }      
    for(int i=1;i<=n;i++)
       if(count[i]>0)
          count[i]++;
    count[arr[0]]--;
    count[arr[n-1]]--;
   
    for(int i=1;i<=n;i++)
       if(count[i]>0 || i==arr[0] || i==arr[n-1])
          min=std::min(min,count[i]);
    if(min<0)
     min=0;
    cout<<min<<endl;     
  }
  return 0;  
}