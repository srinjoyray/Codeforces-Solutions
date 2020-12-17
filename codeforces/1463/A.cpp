#include <bits/stdc++.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<ctype.h>
#define lli long long int 
#define mod 1000003
#define pi 3.141592653589793238
using namespace std;
 
int main()
{ int t;
  cin>>t;
  while(t--)
  { lli a,b,c,sum,num,min;
    cin>>a>>b>>c;
    sum=a+b+c;
    num=sum/9;
    min=std::min(a,b);
    min=std::min(min,c);
    if(sum%9==0 && min>=num)
      cout<<"YES\n";
    else  
      cout<<"NO\n"; 
  }
  return 0;  
}