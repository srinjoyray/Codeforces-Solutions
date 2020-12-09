#include <bits/stdc++.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<ctype.h>
#define lli long long int 
using namespace std;

int main()
{ double r,x,y,a,b,dist;
  cin>>r>>x>>y>>a>>b;
  dist=sqrt(((x-a)*(x-a)) + ((y-b)*(y-b)));// cout<<dist<<endl;
  cout<<ceil(dist/(2*r));
  return 0;  
}