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
    { lli n,rem,num;
      cin>>n;
      int flag=0;
      rem=n%2020;
      num=n/2020;
      if(rem<=num)
        cout<<"YES\n";
      else
        cout<<"NO\n";
         
    }  
    
    return 0;  
}