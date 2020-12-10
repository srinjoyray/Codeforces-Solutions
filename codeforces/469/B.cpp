#include <bits/stdc++.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<ctype.h>
#define lli long long int 
#define mod 1000000007
using namespace std;

int main()
{ int p,q,l,r;
  cin>>p>>q>>l>>r;
  int a[p],b[p],c[q],d[q],count=0,first[5000]={0},flag;
  for(int i=0;i<p;i++)
     cin>>a[i]>>b[i];
  for(int i=0;i<q;i++)
     cin>>c[i]>>d[i];
       
  for(int i=0;i<p;i++)
    for(int j=a[i];j<=b[i];j++)
        first[j]=1;
  for(int k=l;k<=r;k++)        
  { for(int i=0;i<q;i++)
      { flag=0;
        for(int j=c[i]+k;j<=d[i]+k;j++)
           if(first[j]==1)
             {flag=1;break;}
        if(flag==1)
          {count++;break;}
      }   
      
  }
  cout<<count<<endl;
  return 0;  
}