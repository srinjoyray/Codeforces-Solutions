#include <bits/stdc++.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<ctype.h>
using namespace std;

int main()
{ int T;
  cin>>T;
  while(T--)
  { int x,y,max,min,count=0;
    cin>>x>>y;
    max=std::max(abs(x),abs(y));
    min=std::min(abs(x),abs(y));
    count+=2*min;
    max=max-min;
    if(max>0)
       count+=(max*2)-1;
    cout<<count<<endl;
  }
  return 0;  
}