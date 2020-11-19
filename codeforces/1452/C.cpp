#include <bits/stdc++.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<ctype.h>
using namespace std;

int main()
{ int T;
  cin>>T;
  while(T--)
  { char s[200000];
    int len,flag1=0,flag2=0,count=0;
    cin>>s;
    len=strlen(s);
    for(int i=0;i<len;i++)
     { if(s[i]=='(')
          flag1++;
       else if(s[i]=='[')
          flag2++;
       else if(s[i]==')' && flag1>0)
          {count++; flag1--; }
       else if(s[i]==']' && flag2>0)
          {count++; flag2--; }
     }
    cout<<count<<endl;  
  }
  return 0;  
}