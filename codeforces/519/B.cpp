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
    { int n;
      cin>>n;
      lli a[n],b[n-1],c[n-2];
      
      for(int i=0;i<n;i++)
          cin>>a[i];
      for(int i=0;i<n-1;i++)
          cin>>b[i];
      for(int i=0;i<n-2;i++)
          cin>>c[i];
      sort(a,a+n);
      sort(b,b+n-1);
      sort(c,c+n-2);
      for(int i=0;i<n-1;i++)
      { if(a[i]!=b[i])
         { cout<<a[i]<<endl;
           break;
         }
        else if(i==n-2)
          cout<<a[i+1]<<endl;
      }
      for(int i=0;i<n-2;i++)
      { if(b[i]!=c[i])
          { cout<<b[i]<<endl;
            break;  
          }
        else if(i==n-3)
          cout<<b[i+1];
      }
    }  
    
    return 0;  
}