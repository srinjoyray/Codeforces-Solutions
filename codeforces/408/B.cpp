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
{ string a,b;
  cin>>a>>b;
  int freq_a[26]={0},freq_b[26]={0},count=0;
  for(int i=0;i<a.size();i++)
     freq_a[a[i]-'a']++;
  for(int i=0;i<b.size();i++) 
     freq_b[b[i]-'a']++;
  for(int i=0;i<26;i++)
    { count+=std::min(freq_a[i],freq_b[i]);
      if(freq_b[i]>0 && freq_a[i]==0)
        {cout<<"-1";return 0;}
    }
  cout<<count;     
  return 0;  
}