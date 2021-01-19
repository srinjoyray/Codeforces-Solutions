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
int dp[3002][3002];

int main()
{   int t;
    //cin>>t;
    t=1; 
    while(t--)
    { string s,ans;
      cin>>s;
      for(int i=0;i<s.size();i++)
      { if(s[i]=='.')
         { cout<<"0";
           continue;      
         } 
        else if(s[i]=='-' && s[i+1]=='.') 
          {cout<<"1";i++;}
        else if(s[i]=='-' && s[i+1]=='-')
          {cout<<"2";i++;}
        
      }
    }  
    
    return 0;  
}