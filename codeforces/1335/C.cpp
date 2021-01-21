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
      int a[n],temp,max=1,half,count=0;
      for(int i=0;i<n;i++)
         cin>>a[i];
      sort(a,a+n);
      
      for(int i=0,j;i<n;i++)
      { j=i+1;
        while(a[i]==a[j] && j<n)
           j++;
        temp=j-i;
        i=j-1;
        max=std::max(max,temp);
        count++;
      }
      count--;
      //cout<<count<<" "<<max<<" ";
      if(count>=max)
        cout<<max<<endl;
      else
        cout<<std::min(max-1,count+1)<<endl;
    }  
    
    return 0;  
}