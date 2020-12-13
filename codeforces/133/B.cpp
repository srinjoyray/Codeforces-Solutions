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
{ string s,ans;
  cin>>s;
  lli val=0,power=1;
  for(int i=0;i<s.size();i++)
  { switch(s[i])
      { case '>': {ans+="1000";break;}
        case '<': {ans+="1001";break;}  
        case '+': {ans+="1010";break;}
        case '-': {ans+="1011";break;}
        case '.': {ans+="1100";break;}
        case ',': {ans+="1101";break;}
        case '[': {ans+="1110";break;}
        case ']': {ans+="1111";break;}
      }
  }
  for(int i=ans.size()-1;i>=0;i--)
  { if(ans[i]=='1')
       val+=power;
    power*=2;
    val=val%mod;
    power=power%mod;
  }
  cout<<val;
  return 0;  
}