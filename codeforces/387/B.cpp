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
{ int n,m;
  cin>>n>>m;
  int a[n],b[m];
  for(int i=0;i<n;i++)
     cin>>a[i];
  for(int i=0;i<m;i++)
     cin>>b[i];
  sort(a,a+n,greater<int>());
  sort(b,b+m,greater<int>());
 /* for(int i=0;i<m;i++)
    cout<<b[i]<<" ";
  cout<<endl;   
  for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
  cout<<endl;*/ 
  int i=0,j=0,count=0;
  while(i<n && j<m)
   { if(b[j]>=a[i])
       {j++;i++;}
     else
       {count++;i++;}
   }
  count+=n-i; 
  cout<<count; 
  return 0;  
}