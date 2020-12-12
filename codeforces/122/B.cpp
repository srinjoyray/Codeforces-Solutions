#include <bits/stdc++.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<ctype.h>
#define lli long long int 
#define mod 1000000007
using namespace std;
#define pi 3.141592653589793238


int main()
{ string s;
  int four=0,seven=0;
  cin>>s;
  for(int i=0;i<s.size();i++)
     if(s[i]=='4')
        four++;
     else if(s[i]=='7')
        seven++;
  if(four==0 && seven==0)
    cout<<"-1";
  else if(four>=seven)
    cout<<"4";
  else
    cout<<"7";
  return 0;  
}