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
{ double n,x0,y0;
  cin>>n>>x0>>y0;
  double temp1,temp2,temp;
  bool infy=false;
  vector<double> x,y;
  unordered_set<double> slopes;
  for(int i=0;i<n;i++)
    {  cin>>temp1>>temp2;
       if(temp2==y0)
          infy=true;
       else
         { x.push_back(temp1); y.push_back(temp2);}
    }   
  for(int i=0;i<x.size();i++)
  { temp=(x[i]-x0)/(y[i]-y0);
    slopes.insert(temp);  
  }
  if(infy==true)
    cout<<slopes.size()+1;
  else
    cout<<slopes.size();
  return 0;  
}