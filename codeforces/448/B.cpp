#include <bits/stdc++.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<ctype.h>
#define lli long long int 
using namespace std;

int main()
{ string s,t;
  int freq_s[26]={0},freq_t[26]={0},i,j;
  cin>>s>>t;
  for(i=0,j=0;i<t.size() && j<s.size();)
   { if(t[i]==s[j])
        i++,j++;
     else
        j++;
          
   }
  if(i==t.size())
   { cout<<"automaton";
     return 0;  
   }
  for(i=0;i<s.size();i++)
    freq_s[s[i]-'a']++;
  for(i=0;i<t.size();i++)
    freq_t[t[i]-'a']++;
  
  if(s.size()==t.size())
  { for(i=0;i<26;i++)
       if(freq_s[i]!=freq_t[i])
          break;
    if(i==26)
      {cout<<"array";return 0;}
    else
      {cout<<"need tree"; return 0; }
  }
  else
  { for(i=0;i<26;i++)
      if(freq_t[i]>freq_s[i])
        {cout<<"need tree"; return 0; }
  } 
  cout<<"both";
  return 0;  
}