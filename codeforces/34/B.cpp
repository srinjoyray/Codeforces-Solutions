#include <bits/stdc++.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<ctype.h>
#define lli long long int 
#define mod 1000000007
using namespace std;
#define pi 3.141592653589793238


int main()
{ int n,m; 
  cin>>n>>m;
  int arr[n],sum=0;
  for(int i=0;i<n;i++)
      cin>>arr[i];
  sort(arr,arr+n);
  for(int i=0;i<m;i++)
   { if(arr[i]>0)
       break;
     sum+=arr[i];
   }
  cout<<-sum;    
  return 0;  
}