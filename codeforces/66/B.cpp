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
  int arr[n],left[n]={0},right[n]={0},temp,max=1;
  for(int i=0;i<n;i++)
      cin>>arr[i];
  temp=0;      
  for(int i=1;i<n;i++)
  { if(arr[i]>=arr[i-1])
      temp++;
    else
      temp=0;
    left[i]=temp;  
  }
  temp=0;
  for(int i=n-2;i>=0;i--)
  { if(arr[i]>=arr[i+1])
      temp++;
    else
      temp=0;
    right[i]=temp;  
  }
  for(int i=0;i<n;i++)
     max=std::max(max,left[i]+right[i]+1);
  
  cout<<max;     
  return 0;  
}