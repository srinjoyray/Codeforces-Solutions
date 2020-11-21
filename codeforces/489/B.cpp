#include <bits/stdc++.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<ctype.h>
using namespace std;
 
int main()
{ int n,m,i=0,j=0,pair=0;
  cin>>n;
  int boy[n];
  for(int i=0;i<n;i++)
     cin>>boy[i];
  cin>>m;
  int girl[m];
  for(int i=0;i<m;i++)
     cin>>girl[i];
  sort(girl,girl+m);
  sort(boy,boy+n);
  while(i<n && j<m)
  { if(abs(boy[i]-girl[j])<=1)
     { pair++; i++;j++;}
     else if(boy[i]>girl[j])
        j++;
     else if(girl[j]>boy[i])
        i++;
  }
  cout<<pair;
  return 0;  
}