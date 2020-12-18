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
{ string s,num,ans,dec;
  bool neg=false;
  int flag=0;
  cin>>s;
  if(s[0]=='-')
  { neg=true;
    s.erase(0,1);  
  }
  for(int i=0;i<s.size();i++)
  { if(s[i]=='.')
      {flag=1;continue;}
    if(flag==0)
      num.push_back(s[i]);
    else
      dec.push_back(s[i]);
    if(dec.size()==2)
      break;
  }
  for(int i=num.size()-1,count=0;i>=0;i--)
  { count++;
    ans.push_back(num[i]);
    if(count%3==0 && i>0)
       ans.push_back(',');  
  }
  reverse(ans.begin(),ans.end());
  if(dec.size()==0)
    dec+="00";
  else if(dec.size()==1)
    dec+='0';

  if(neg==true)
    cout<<"(";
  cout<<"$"<<ans<<"."<<dec;
  if(neg==true)
    cout<<")";
  
  return 0;  
}