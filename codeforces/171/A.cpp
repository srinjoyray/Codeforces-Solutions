#include <bits/stdc++.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<ctype.h>
using namespace std;
 
int main()
{ long int a1,a2,rev=0,digit;
  cin>>a1>>a2;
  while(a2)
  { digit=a2%10;
    rev=rev*10+digit;
    a2/=10;
  }
  cout<<a1+rev<<endl;
  return 0;  
}