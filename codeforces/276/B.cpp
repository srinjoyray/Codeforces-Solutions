#include <bits/stdc++.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<ctype.h>
#define lli long long int 
#define mod 1000000007
using namespace std;

int main()
{ string s;
  int flag=0,freq[26]={0},odd=0;
  cin>>s;
  for(int i=0;i<s.size();i++)
    freq[s[i]-'a']++;
  for(int i=0;i<26;i++)
    if(freq[i]%2==1)
      odd++;
  if(odd<=1)
    cout<<"First";
  else if(odd%2==0)
    cout<<"Second";
  else
    cout<<"First";
    
    
  return 0;  
}