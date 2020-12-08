#include <bits/stdc++.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<ctype.h>
using namespace std;

void binary(int x,int n,char s[])
{ int value=pow(2,n-1);
  
  for(int i=0;i<n;i++)
   { if(x>=value)
       {s[i]='1'; x-=value;}    
     else
        s[i]='0';
     value/=2;    
   } 
    
}

int main()
{ int n,m,k,count=0,temp_count,diff;
  cin>>n>>m>>k;
  int arr[m+1];
  char a[n+1];
  
  for(int i=0;i<m+1;i++)
    cin>>arr[i];
  binary(arr[m],n,a);
 /* for(int i=0;i<n;i++)
         cout<<a[i];
      cout<<endl;*/
  for(int i=0;i<m;i++)
    { temp_count=0;
      char b[n+1];
      binary(arr[i],n,b);
      for(int i=0;i<n;i++)
        if(a[i]!=b[i])
          temp_count++;
      if(temp_count<=k)
        count++;
      /*for(int i=0;i<n;i++)
         cout<<b[i];
      cout<<endl;*/     
    }
   cout<<count;    
  return 0;  
}