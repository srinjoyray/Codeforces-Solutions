#include <bits/stdc++.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<ctype.h>
#define lli long long int 
using namespace std;

int main()
{ string s;
  int k,w[26],val=0,max=0;
  cin>>s>>k;
  for(int i=0;i<26;i++)
    {cin>>w[i]; max=std::max(max,w[i]);}
  for(int i=0;i<s.size();i++)
    val+=(w[s[i]-'a'])*(i+1); //cout<<val<<endl<<max<<endl;
  for(int i=s.size()+1;i<=s.size()+k;i++)
    val+=i*max;
  cout<<val;    
 return 0;  
}