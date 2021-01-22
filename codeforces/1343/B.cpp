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
    { int n,len;
      cin>>n;
      len=n/2;
      if(len%2==1)
        { cout<<"NO\n";
          continue;
        }
      cout<<"YES\n";
      lli start=2,sum=0;
      for(int i=1;i<=len;i++)
      { cout<<start<<" ";
        sum+=start;
        start+=2;
      } 
      start=1;
      for(int i=1;i<=len;i++)
      { if(i==len)
          cout<<sum<<endl;
        else
         { cout<<start<<" ";
           sum-=start;
           start+=2;
         }
      } 
    }  
    
    return 0;  
}