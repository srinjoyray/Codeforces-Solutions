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
{ long int n,t,temp,start,end,max=0,last;
  cin>>n>>t;
  int arr[n],cum[n+1]={0};
  for(int i=0;i<n;i++)
     cin>>arr[i]; 
  for(int i=1;i<=n;i++)
     cum[i]+=cum[i-1]+arr[i-1];
 /* for(int i=0;i<=n;i++)
    cout<<cum[i]<<" ";
  cout<<endl;*/    
  start=0;end=1; last=cum[n];
  while(end<=n)
  {  temp=cum[end]-cum[start];
        if(temp<=t)
         { max=std::max(max,end-start);
            end++;
         }
        else
            start++;
   
  }
  cout<<max;
  return 0;  
}