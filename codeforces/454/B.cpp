#include <bits/stdc++.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<ctype.h>
#define lli long long int 
#define mod 1000000007
using namespace std;

int main()
{ int n,pos,first,flag=0;
  cin>>n;
  pos=n;
  int arr[n];
  for(int i=0;i<n;i++)
     cin>>arr[i];
  first=arr[0];     
  for(int i=1;i<n;i++)
    { if(arr[i]<arr[i-1])
       { pos=i;
         if(arr[i]>first)
           {flag=1;break;}
         for(int j=pos+1;j<n;j++)
          { if(arr[j]<arr[j-1] || arr[j]>first)
             {flag=1;break;}
            flag=2; 
          }
         if(flag>0)
           break;
       }
        
    }
    if(flag==1)
     cout<<"-1";
    else 
     cout<<n-pos;
  return 0;  
}