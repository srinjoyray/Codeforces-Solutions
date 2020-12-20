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
{  double l,d,v,g,r,add,timer;
   cin>>l>>d>>v>>g>>r;
   timer=d/v;
   while((g+r)<timer)
     timer-=(g+r);
   if(timer<g)
     add=0;
   else
     add=g+r-timer;
   add+=l/v;
   cout<<fixed<<setprecision(7);
   cout<<add;
   return 0;  
}