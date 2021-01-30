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
    { lli n,m,sum=0,lim,min,temp;
      cin>>n>>m;
      lim=n/m;
      min=lim/10;
      if(lim==0)
       { cout<<0<<endl;
         continue;  
       }
      for(int i=1;i<=9;i++)
      { if(lim%10>=i)
          temp=min+1;
        else
          temp=min;
        sum+=temp*((m*i)%10);  
       // cout<<sum<<endl;
      }
      cout<<sum<<endl;
    }  
    
    return 0;  
}