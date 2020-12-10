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
{ int n;
  cin>>n;
  int arr[n],max,temp;
  max=std::min(2,n);
  for(int i=0;i<n;i++)
    cin>>arr[i];
  temp=max;    
  for(int i=2;i<n;i++)
    { if(arr[i]==arr[i-1]+arr[i-2])
        temp++;
      else
       temp=2;
      max=std::max(max,temp); 
    }
  cout<<max;    
  return 0;  
}