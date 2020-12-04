#include <bits/stdc++.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<ctype.h>
using namespace std;
 
int main()
{ int n,t;
  cin>>n>>t;
  string s;
  cin>>s;
  while(t--)
  { for(int i=1;i<n;)
       if(s[i]=='G' && s[i-1]=='B')
         { s[i-1]='G';
           s[i]='B';
           i+=2;
         }
       else 
         i++;
  }
  cout<<s;
  return 0;  
}