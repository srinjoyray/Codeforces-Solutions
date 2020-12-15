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
{ 
  lli p,d,k=1,num,power,temp;
  cin>>p>>d;
  temp=p;
  while(temp%10==9)
  { k++;
    temp/=10;  
  }
  temp=p;
  while(true)
  { power=pow(10,k);
    num=p-(p%power)-1;
    k++;
    if(num==-1)
      break;
    if(p-num<=d)  
      temp=num;
    else
      break;
  }
  cout<<temp;
  return 0;  
 
}