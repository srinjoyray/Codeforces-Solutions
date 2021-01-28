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
    //cin>>t;
    while(t--)
    { int n;
      cin>>n;
      lli v[n],u[n],pre_u[n+1]={0},pre_v[n+1]={0};
      for(int i=0;i<n;i++)
      {  cin>>v[i];
         u[i]=v[i]; 
      }
      sort(u,u+n);
      for(int i=1;i<=n;i++)
        pre_u[i]=pre_u[i-1]+u[i-1];
      for(int i=1;i<=n;i++)
        pre_v[i]=pre_v[i-1]+v[i-1];
      int m;
      cin>>m;
      while(m--)
      { int type,l,r;
        cin>>type>>l>>r;
        if(type==1)
          cout<<pre_v[r]-pre_v[l-1]<<endl;
        else
          cout<<pre_u[r]-pre_u[l-1]<<endl;
      }
          
    }  
    
    return 0;  
}