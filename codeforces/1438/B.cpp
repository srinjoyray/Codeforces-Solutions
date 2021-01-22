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
    { int n,flag=0;
      cin>>n;
      lli a[n];
      for(int i=0;i<n;i++)
        cin>>a[i];
      map<lli,lli> mp;
      for(int i=0;i<n;i++)
      { mp[a[i]]++;
        if(mp[a[i]]>=2)
          {flag=1;break;}
      }
      if(flag==0)
        cout<<"NO\n";
      else 
        cout<<"YES\n";
    }  
    
    return 0;  
}