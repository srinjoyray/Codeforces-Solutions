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
    { lli n,k;
      cin>>n>>k;
      double p[n];
      lli temp,ans=0,prefix[n];
      
      for(int i=0;i<n;i++)
         cin>>p[i];
      prefix[0]=p[0];  
      for(int i=1;i<n;i++)
         prefix[i]=prefix[i-1]+p[i];
     /* for(int i=0;i<n;i++)
        cout<<prefix[i]<<" ";
      cout<<endl;    */
      for(int i=n-1;i>0;i--)
      { temp=ceil((p[i]*100)/k);
        if(temp-prefix[i-1]>ans)
          ans=temp-prefix[i-1];
        //cout<<i<<" "<<temp<<endl; 
      }
       
      cout<<ans<<endl;
    }  
    
    return 0;  
}