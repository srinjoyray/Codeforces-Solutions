#include <bits/stdc++.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<ctype.h>
#define lli long long int 
#define mod 1000003
#define pi 3.141592653589793238
using namespace std;
int main()
{   int t;
    cin>>t;
    while(t--)
    { int n;
      cin>>n;
      string s;
      cin>>s;
      int count=0,rem;
      for(int i=n-1;i>=0;i--)
        if(s[i]==')')
          count++;
        else
          break;
      rem=n-count;
      if(count>rem)
        cout<<"Yes\n";
      else
        cout<<"No\n";
        
    }
    return 0;  
    
}