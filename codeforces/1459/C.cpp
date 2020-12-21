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
lli gcd(lli a, lli b)
{ if(b==0)
     return a;
  return gcd(b,a%b);     
    
}

int main()
{   int n,m;
    cin>>n>>m;
    lli a[n],b[m],hcf;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<m;i++)
        cin>>b[i];
    if(n==1)
     { for(int i=0;i<m;i++)
          cout<<b[i]+a[0]<<" ";
       return 0;      
     }
    hcf=a[1]-a[0];
    for(int i=2;i<n;i++)
       hcf=gcd(hcf,a[i]-a[0]);
    for(int i=0;i<m;i++)
       cout<<abs(gcd(hcf,b[i]+a[0]))<<" ";
    return 0;  
    
}