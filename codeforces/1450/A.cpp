#include <bits/stdc++.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<ctype.h>
using namespace std;
 
int main()
{ int t;
  cin>>t;
  while(t--)
  { int n,count=0;
    cin>>n;
    string s,ans;
    char store='b';
    cin>>s;
    for(int i=0;i<n;i++)
       if(s[i]=='b')
         count++;
    while(count--)
    { ans.push_back(store);
    }
    for(int i=0;i<n;i++)
      if(s[i]=='b')
        continue;
      else
        ans.push_back(s[i]);
    cout<<ans<<endl;
  }
 
  return 0;  
}