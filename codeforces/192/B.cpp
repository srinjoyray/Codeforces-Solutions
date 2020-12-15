#include <bits/stdc++.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<ctype.h>
#define lli long long int 
#define mod 1000003
#define pi 3.141592653589793238
using namespace std;
 
int main()
{ int n;
  cin>>n;
  int arr[n],min;
  for(int i=0;i<n;i++)
      cin>>arr[i];
  min=std::min(arr[0],arr[n-1]);
  for(int i=1;i<=n-3;i++)
     min=std::min(min,std::max(arr[i],arr[i+1]));
  cout<<min;
  return 0;  
 
}