#include <bits/stdc++.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<ctype.h>
#define lli long long int 
#define mod 1000000007
#define pi 3.141592653589793238
using namespace std;

int main()
{   int t=1;
    cin>>t;
    while(t--)
    { lli n,k,flag=1;
      cin>>n>>k;
      if((n+k)%2==1)
        flag=0;
      if(n<(k*k))
        flag=0;
      if(flag==1)
        cout<<"YES\n";
      else
        cout<<"NO\n";
    }  
    
    return 0;  
}