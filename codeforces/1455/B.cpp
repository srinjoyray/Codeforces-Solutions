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
  { long x;
    cin>>x;
    long sum=1,count=1,num=1;
    while(sum<x)
    { num++;
      sum+=num;
      count++;    
    }
    if(sum-1==x)
      cout<<count+1<<endl;
    else
      cout<<count<<endl;
  }
  return 0;  
}