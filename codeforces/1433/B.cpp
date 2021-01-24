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
    cin>>t;
    //t=1; 
    while(t--)
    { int n;
      cin>>n;
      int a[n],total=0,left=0,right=0;
      for(int i=0;i<n;i++)
         cin>>a[i];       
      for(int i=0;i<n;i++)
         if(a[i]==0)
           total++;
      for(int i=0;i<n;i++)
         if(a[i]==1)
           break;
         else
           left++;
      for(int i=n-1;i>=0;i--)
         if(a[i]==1)
            break;
         else
            right++;
      if(left+right>=total || total==n)
        cout<<"0\n";
      else
        cout<<total-(left+right)<<endl;
    }  
    
    return 0;  
}