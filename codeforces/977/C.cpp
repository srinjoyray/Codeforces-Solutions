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
    { int n,k;
      cin>>n>>k;
      lli a[n],ans;
      for(int i=0;i<n;i++)
         cin>>a[i];
      sort(a,a+n);
      if(k==0)
      { if(a[0]==1)
          cout<<"-1\n";
        else
          cout<<"1\n";
        continue;  
      }
      if(k==n)
      { cout<<1000000000<<endl;
        continue; 
      }
      ans=a[k];
      if(a[k-1]==a[k]) 
        cout<<"-1\n";
      else
        cout<<ans-1<<endl;
    }  
    
    return 0;  
}