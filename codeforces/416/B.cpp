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
{ int m,n;
  cin>>m>>n;
  int arr[m][n],painter[m][n]={0},prev=0;
  for(int i=0;i<m;i++)
      for(int j=0;j<n;j++)
          cin>>arr[i][j]; 
  for(int i=0;i<m;i++)
    {  
      for(int j=0;j<n;j++)
        { int temp1=0,temp2=0;
          if(i>0)
            temp1=painter[i-1][j];
          if(j>0)
            temp2=painter[i][j-1];
          prev=std::max(temp1,temp2);    
          painter[i][j]=prev+arr[i][j];
          
        }
      cout<<painter[i][n-1]<<" ";    
    }    
  return 0;  
}