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
    { lli n,k,ans,temp;
      cin>>n>>k;
      if(n==1)
      { cout<<k<<endl;
        continue;
      } 
      if(k==n)
       ans=1;
      else if(n>k)
      { if(n%k==0)
         ans=1;
        else 
         ans=2;
          
      }
      else if(k>n)
      { temp=k%n;
        ans=k/n;  
        if(temp>0)
          ans++;
      }    
     cout<<ans<<endl;   
    }  
    
    return 0;  
}