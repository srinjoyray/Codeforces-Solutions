#include <bits/stdc++.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<ctype.h>
using namespace std;

int main()
{ int n,m,a,b;
  long int cost1,cost2;
  cin>>n>>m>>a>>b;
  cost1=n*a;
  cost2=((n/m)*b) +(min (((n%m)*a),b));
  cout<<min(cost1,cost2);
  return 0;  
}