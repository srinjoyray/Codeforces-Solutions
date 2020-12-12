#include <bits/stdc++.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<ctype.h>
#define lli long long int 
#define mod 1000000007
using namespace std;
#define pi 3.141592653589793238

bool comp( pair<int,int> &a,pair<int,int> &b)
{ if(a.second==b.second)
     return(a.first>b.first); 
  return (a.second>b.second);
    
}

int main()
{ int n;
  cin>>n;
  vector <pair<int,int>> v;
  for(int i=0;i<n;i++)
     { int temp1,temp2;
       cin>>temp1>>temp2;
       v.push_back({temp1,temp2});     
     }
  sort(v.begin(),v.end(),comp);       
  int count=1,i=0,sum=0;
  while(count>0 && i<n)
  { sum+=v[i].first;
    count+=v[i].second;  
    count--;
    i++;
  }
  cout<<sum;
  return 0;  
}