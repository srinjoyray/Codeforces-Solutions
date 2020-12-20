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
{  lli w,h,x=0,y=0;
   cin>>w>>h;
   if(w<2 || h<2)
    {cout<<"0";return 0;}
   for(int i=2;i<=w;i+=2)
   { x+=w-i+1;
       
   }
   for(int i=2;i<=h;i+=2)
   { y+=h-i+1;
       
   } //cout<<x<<" "<<y<<endl;
   cout<<x*y;
    return 0;  
}