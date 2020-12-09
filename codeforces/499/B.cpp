#include <bits/stdc++.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<ctype.h>
using namespace std;

int main()
{ int n,m;
  cin>>n>>m;
  string a[m],b[m],prof[n];
  for(int i=0;i<m;i++)
     cin>>a[i]>>b[i]; 
  for(int i=0;i<n;i++)
     cin>>prof[i];
  for(int i=0;i<n;i++)
   { //cout<<prof[i]<<endl;
     for(int j=0;j<m;j++)
       if((prof[i].compare(a[j])==0)||(prof[i].compare(b[j])==0)) 
          { 
            if(a[j].size()>b[j].size())
               cout<<b[j];
            else
               cout<<a[j];
            cout<<" ";  
            break;   
          }
          
   } 
  return 0;  
}