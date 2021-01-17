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
    { int n,temp=0;
      cin>>n;
      string s,ans;
      cin>>s;
      for(int i=0;i<n;i++)
      { ans.push_back(s[i+temp]);
        temp++;  
      }
      cout<<ans<<endl;
    }  
    
    return 0;  
}