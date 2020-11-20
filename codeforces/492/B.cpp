#include <bits/stdc++.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<ctype.h>
//#include<iomanip.h>
using namespace std;
 
int main()
{ int n;
  double l, diff; 
  cin>>n>>l;
  double arr[n];
  for(int i=0;i<n;i++)
      cin>>arr[i];
  sort(arr,arr+n);
  diff=arr[1]-arr[0];
  for(int i=1;i<n-1;i++)
      diff=std::max(diff,arr[i+1]-arr[i]);
  diff=diff/2;  
  diff=std::max(diff,arr[0]);
  diff=std::max(diff,l-arr[n-1]);
  
  cout<<fixed;
  cout<<setprecision(9);
  cout<<diff;
  return 0;  
}