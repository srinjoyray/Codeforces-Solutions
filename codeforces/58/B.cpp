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
{ lli n,temp;
  cin>>n;
  
  while(n)
  { cout<<n<<" ";
    temp=n;
    if(n==1)
      break;
    for(int i=2;i*i<=n;i++)
       { if(n%i==0)
            {n/=i;break;}
         
       }
       
    if(n==temp)
      {cout<<"1";break;}
  }
  return 0;  
}