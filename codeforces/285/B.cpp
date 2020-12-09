#include <bits/stdc++.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<ctype.h>
#define lli long long int 
using namespace std;

int main()
{ int n,s,t;
  cin>>n>>s>>t;
  int arr[n+1],count=0,pos,flag=0,freq[n+1]={0};
  for(int i=1;i<=n;i++)
     cin>>arr[i];
  pos=s;
  while(true)
  { if(pos==t)
       break;
    freq[pos]++;
    if(freq[pos]>1)
      {flag=1;break;}
    pos=arr[pos];
    count++;
  }
  if(flag==1)
    cout<<"-1\n";
  else    
    cout<<count;
  return 0;  
}