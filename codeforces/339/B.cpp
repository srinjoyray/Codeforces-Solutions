#include <bits/stdc++.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<ctype.h>
using namespace std;

int main()
{ int n,m,start=1;
  cin>>n>>m;
  int arr[m];
  long long t=0;
  for(int i=0;i<m;i++)
     cin>>arr[i]; 
  for(int i=0;i<m;i++)
     { if(arr[i]>=start)
          t+=arr[i]-start;
       else
          t+=n-start+arr[i];
       start=arr[i];      
     } 
  cout<<t;     
  return 0;  
}