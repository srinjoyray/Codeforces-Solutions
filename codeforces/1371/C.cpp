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
{   int t;
    cin>>t;
    //t=1; 
    while(t--)
    { lli a,b,n,m;
      cin>>a>>b>>n>>m;
      if(m+n>a+b)
      { cout<<"NO\n"; 
        continue;
      }
      //cout<<std::min(a,b)<<" "<<m<<endl;
      if(m<=std::min(a,b))
       cout<<"YES\n";
      else
       cout<<"NO\n";
    }  
    
    return 0;  
}