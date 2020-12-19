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
{ int m;
  cin>>m;
  int freq[6]={0},a,b,flag=0;
  for(int i=1;i<=m;i++)
   { cin>>a>>b;
     freq[a]++;
     freq[b]++;  
   }
  for(int i=1;i<=5;i++)
     if(freq[i]>=3)
       {flag=1;break;}
  for(int i=1;i<=5;i++)
     if(freq[i]<=1)
       {flag=1;break;}
  if(flag==1) 
    cout<<"WIN";
  else
    cout<<"FAIL";
  return 0;  
}