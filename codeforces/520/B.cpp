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
    //cin>>t;
    t=1; 
    while(t--)
    { int n,m;
      cin>>n>>m;
      if(n==m)
        cout<<"0\n";
      else if(m>n)
      { int count=0;
        while(n!=m)
        { if(m<n || m%2==1)
            {m++; count++;}
          else
            {m/=2;count++;}
        }
        cout<<count<<endl;
      }
      else if(m<n)
      {
          cout<<n-m<<endl;
      }
    }  
    
    return 0;  
}