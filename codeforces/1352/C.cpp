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
    { lli n,k,len,jump,ans;
      cin>>n>>k;
      len=n-1;
      jump=k/len;
      ans=n*jump;
      if(k%len==0)
         ans--;
      else
      { ans+=k%len;
          
      }
      cout<<ans<<endl;
    }  
    
    return 0;  
}