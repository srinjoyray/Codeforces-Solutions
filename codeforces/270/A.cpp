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
  { int a;
    cin>>a;
    if(360%(180-a)==0)
       cout<<"YES\n";
    else
       cout<<"NO\n";
  }
  return 0;  
}