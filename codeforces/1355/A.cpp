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
    { lli a,k,temp,max,min,digit;
      cin>>a>>k;
      for(int i=1;i<k;i++)
      { temp=a;
        max=temp%10;
        min=temp%10;
        while(temp)
        { digit=temp%10;
          if(digit>max)
            max=digit;
          if(digit<min)
            min=digit;
          temp/=10;    
        }
        if(min==0)
          break;
        a+=min*max;  
      }
      cout<<a<<endl;
      
    }  
    
    return 0;  
}