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
    { string s;
      lli n;
      cin>>s;
      n=s.size();
      lli res=0,init=0,curr,flag=0,prefix[n+1],temp=0;
      for(int i=0;i<=n;i++)
        prefix[i]=-1;
      for(int i=0;i<n;i++)
      { if(s[i]=='+')
          temp++;
        else
          temp--;
        if(temp>=0)
          continue;
        if(prefix[-temp]==-1)
           prefix[-temp]=i+1;
      }
      for(int i=1;i<=n;i++)
      { temp=i;
        if(prefix[temp]==-1)
         { res+=n; break; }
        else
          res+=prefix[temp];
        if(i==n)
          res+=n;
      }
      
     /* for(int i=1;i<=n;i++)
         cout<<prefix[i]<<" ";
      cout<<endl;*/ 
      
      cout<<res<<endl;
    }  
    
    return 0;  
}