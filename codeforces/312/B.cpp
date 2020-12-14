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
{ float a,b,c,d,prob1,prob2,r,prob;
  cin>>a>>b>>c>>d;
  prob1=a/b;
  prob2=c/d;
  r=(1-prob1)*(1-prob2);
  prob=prob1/(1-r);
  cout<<prob;
  return 0;  
}