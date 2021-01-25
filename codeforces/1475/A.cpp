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
    { lli n;
      cin>>n;
      int flag=0;
      while(n>1)
      { if(n%2==1)
         { flag=1;
           break;
         }
        n/=2;     
      }
      if(flag==0)
         cout<<"NO\n";
      else
         cout<<"YES\n";
    }  
    
    return 0;  
}