#include <bits/stdc++.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<ctype.h>
#define lli long long int 
using namespace std;

int main()
{ int n;
  cin>>n;
  int arr[n],count=0,temp,pos=0,ht=0;
  for(int i=0;i<n;i++)
     cin>>arr[i];
  while(pos<n)
  { count+=abs(arr[pos]-ht)+1;
    ht=arr[pos];
    if(pos==n-1)
      break;
    pos++;
    count++;
     
      
  }
  cout<<count;
  return 0;  
}