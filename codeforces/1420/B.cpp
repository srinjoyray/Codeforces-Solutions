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
      lli a[n],temp,gap,ans=0;
      for(int i=0;i<n;i++)
         cin>>a[i];
      sort(a,a+n);
      for(int i=0;i<n;i++)
      { temp=1;
        while(temp<=a[i])
        { temp*=2;
              
        }
        temp/=2;
        a[i]=temp;
      }
      sort(a,a+n);
      for(int i=0,j;i<n;i++)
      { j=i+1;
        while(a[j]==a[i] && j<n)  
           j++;
        
        gap=j-i;
        i=j-1;
        if(gap>=2)
         ans+=(gap*(gap-1))/2;
      }
      cout<<ans<<endl;
    }  
    
    return 0;  
}