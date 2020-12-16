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
lli solve(lli n,lli f)
{ lli D,sq,denom,num,number,sum=0,temp;
  D=f*f+(4*n);
  sq=sqrt(D);
  if(sq*sq!=D)
    return -1;
  num=-f+sq;
  denom=2;
  if(num%denom!=0)
    return -1;
  number=num/denom; 
  temp=number;
  while(number)
  { sum+=number%10;
    number/=10;  
  }
  if(sum==f)
     return temp;
  return -1;     
}

int main()
{ lli n,res;
  cin>>n;
  for(int i=1;i<=90;i++)
  { res=solve(n,i);
    if(res>0)
       {cout<<res;break;}
    if(i==90)
      {cout<<"-1";break;}
  }
  return 0;  
 
}