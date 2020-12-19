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
int func(int x)
{
   return (x & -x);
}
int main()
{   int sum,limit,val;
    cin>>sum>>limit;
    vector<int> v;
    for(int i=limit;i>=1;i--)
    { val=func(i);
      if(sum>=val)
       { v.push_back(i);
         sum-=val;  //test
       }
      if(sum==0)
        break;
    }
    if(sum==0)
    { cout<<v.size()<<endl;
      for(int i=0;i<v.size();i++)
         cout<<v[i]<<" ";
    }
    else
      cout<<"-1";
    return 0;  
}