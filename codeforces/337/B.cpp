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

lli gcd(lli a,lli b)
{ if(b==0)
    return a;
  return gcd(b,a%b);     
}
lli lcm(lli a,lli b)
{
    return (a*b)/gcd(a,b);
}
int main()
{ lli a,b,c,d,len,fact1,fact2,area,empty,hcf;
  cin>>a>>b>>c>>d;
  len=lcm(lcm(a,b),lcm(c,d)); //cout<<len<<endl;
  float temp_a,temp_b,temp_c,temp_d;
  temp_a=float(a); temp_b=float(b); temp_c=float(c); temp_d=float(d);
  if(temp_a/temp_b<temp_c/temp_d)
  { 
    fact1=len/a; 
    fact2=len/c;  
    a=len; c=len;
    b=b*fact1; d=d*fact2;
  }
  else if(temp_a/temp_b>temp_c/temp_d)
  {
    fact1=len/b;
    fact2=len/d;
    b=len; d=len;
    a=a*fact1; c=c*fact2;  
  }
  else
  { c=a;
    d=b;  
  }// cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl; 
  if(a==c)
  { area=b; 
    empty=b-d;
  }
  else if(b==d)
  {area=a;
   empty=a-c;
  } 
  hcf=gcd(area,empty);
  area/=hcf;
  empty/=hcf;
  cout<<empty<<"/"<<area;
  return 0;  
  
}