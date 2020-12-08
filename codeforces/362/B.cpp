#include <bits/stdc++.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<ctype.h>
using namespace std;

int main()
{ long n,m,flag=0;
  cin>>n>>m;
  long arr[m];
  for(int i=0;i<m;i++)
      cin>>arr[i];
  sort(arr,arr+m);
  for(int i=0;i<m-2;i++)
    if(arr[i+2]-arr[i]==2)
       {flag=1;break;}
  if(arr[0]==1 || arr[m-1]==n)
     flag=1;
  if(flag==1)
     cout<<"NO";
  else
     cout<<"YES";
  return 0;  
}