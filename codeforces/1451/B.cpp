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
  { int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    while(q--)
    { int l,r,flag=0;
      cin>>l>>r;
      l--;r--;
      char char1=s[l];
      char char2=s[r];
      for(int i=0;i<l;i++)
          if(s[i]==char1)
            { flag=1; break; }
      for(int i=r+1;i<n && flag==0;i++)
          if(s[i]==char2)
            { flag=1; break; }
      if(flag==1)
         cout<<"YES\n";
      else         
         cout<<"NO\n";        
    }
  }
  return 0;  
}