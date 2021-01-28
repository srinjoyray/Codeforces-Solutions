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
{   int t=1;
    cin>>t;
    while(t--)
    { int n;
      cin>>n;
      int a[n],freq[1001]={0},max=0;
      for(int i=0;i<n;i++)
      {   cin>>a[i];
          freq[a[i]]++;
      }
      for(int i=1;i<=1000;i++)
         max=std::max(max,freq[i]);
      cout<<max<<endl;     
    }  
    
    return 0;  
}