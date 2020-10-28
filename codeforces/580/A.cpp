#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

int main()
{ int n,count=1,max=1;
  cin>>n;
  long int arr[n];
  for(int i=0;i<n;i++)
      cin>>arr[i];
  for(int i=1;i<n;i++)
     { if(arr[i]>=arr[i-1])
          count++;
       else
         { if(count>max)
              max=count;
           count=1;      
             
         }
     }
  if(count>max)
      max=count;
  cout<<max;  
        
  return 0;  
}