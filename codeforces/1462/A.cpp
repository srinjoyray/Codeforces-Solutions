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
{ int t;
  cin>>t;
  while(t--)
  { int n;
    cin>>n;
    int arr[n],count=0;
    vector<int> v;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=0,j=n-1;i<=j;i++,j--)
    { if(i==j)
        v.push_back(arr[i]);
      else    
        {v.push_back(arr[i]);
         v.push_back(arr[j]);
        } 
        
    }
    for(int i=0;i<n;i++)
       cout<<v[i]<<" ";
    cout<<endl;   
  }        
  return 0;  
 
}