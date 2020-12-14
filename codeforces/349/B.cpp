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
bool comp(pair<int,int> &a,pair<int,int> &b)
{ if(a.first==b.first)
     return (a.second>b.second);
  return (a.first<b.first);     
}

int main()
{ int n,temp;
  vector<pair<int,int>> v;
  cin>>n;
  int val,digit,arr[9],sum;
  string ans;
  for(int i=1;i<=9;i++)
    { cin>>temp;
      arr[i-1]=temp;
      v.push_back({temp,i});
    }  
  sort(v.begin(),v.end(),comp);
  val=v[0].second;
  digit=n/v[0].first;
  sum=digit*v[0].first;//cout<<digit<<" "<<val<<endl;
  sum=n-sum;//cout<<sum<<endl;
  if(digit==0)
    {cout<<"-1";return 0;}
  for(int i=0;i<digit;i++)
     ans+=to_string(val);
  for(int i=0,j;i<digit;i++)
  { if(sum==0) 
      break;
    for(j=8;j>=val;j--) 
       if(arr[j]-v[0].first<=sum)
          {ans[i]='0'+j+1;
           sum-=arr[j]-v[0].first;
           break;
              
          }
    if(j==val-1)
       break;
  }
  for(int i=0;i<digit;i++)
     cout<<ans[i];
  return 0;  
  
}