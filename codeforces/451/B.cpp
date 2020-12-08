#include <bits/stdc++.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<ctype.h>
using namespace std;

int main()
{ int n,start,end,flag=0;
  cin>>n;
  long arr[n],copy[n];
  for(int i=0;i<n;i++)
     {cin>>arr[i]; copy[i]=arr[i];}
  sort(copy,copy+n);
  start=0;
  end=n-1;
  for(int i=0;i<n;i++)
     if(arr[i]==copy[i])
        start++;
     else
        break;
  for(int i=n-1;i>=0;i--)
     if(arr[i]==copy[i])
         end--;
     else
         break;
           
  for(int i=start,j=end;i<=end;i++,j--)
      if(arr[i]!=copy[j])
        {flag=1; break;}
  if(start==n && end==-1)
     {start=0;end=0;}
  if(flag==1)
     cout<<"no";
  else
     cout<<"yes"<<endl<<start+1<<" "<<end+1;
  return 0;  
}