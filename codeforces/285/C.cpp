#include <bits/stdc++.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<ctype.h>
#define lli long long int 
#define mod 1000000007
#define pi 3.141592653589793238
using namespace std;

int main()
{   int t;
    //cin>>t;
    t=1; 
    while(t--)
    { int n;
      cin>>n;
      lli a[n],count=0;
      for(int i=0;i<n;i++)
        cin>>a[i];
      sort(a,a+n);    
      for(int i=0;i<n;i++)
        count+=abs(a[i]-(i+1)); 
      cout<<count<<endl;          
           
    }  
    
    return 0;  
}