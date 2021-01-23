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
    { int n;
      cin>>n;
      int p[n],c[n];
      //cout<<t<<" ";
      for(int i=0;i<n;i++)
         cin>>p[i]>>c[i];
      if(c[0]>p[0])
        {cout<<"NO\n";
         continue;
        }
      for(int i=1;i<n;i++)
        if(c[i]-c[i-1]>p[i]-p[i-1] || c[i-1]>c[i])
          { cout<<"NO\n";
            break;
          }
        else if(i==n-1)
          cout<<"YES\n";
      if(n==1)
        cout<<"YES\n";
    }  
    
    return 0;  
}