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
{ int n,set;
  cin>>n;
  set=n/4;
  for(int i=1;i<=set;i++)
    cout<<"abcd";
  for(int i=1;i<=n%4;i++)
   { if(i==1)
        cout<<"a";
     if(i==2)
        cout<<"b";
     if(i==3)
        cout<<"c";
   }
  return 0;  
}