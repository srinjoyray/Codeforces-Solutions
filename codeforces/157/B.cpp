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

double area(double r)
{   
    return pi*r*r;
}
int main()
{ int n; 
  cin>>n;
  double arr[n],sum=0;
  for(int i=0;i<n;i++)
    cin>>arr[i];
  sort(arr,arr+n,greater<int>()); 
  for(int i=0;i<n;i+=2)
  { if(i==n-1)
      sum+=area(arr[i]);
    else
      sum+=area(arr[i])-area(arr[i+1]);
  }
  cout<<sum;
  return 0;  
}