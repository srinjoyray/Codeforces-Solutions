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
  { long long int n,flag=0,sum=0,position,pos[n],x=0;
    long long int W,half;
    cin>>n>>W;
    long long  int w[n];
    for(long long int i=0;i<n;i++)
       cin>>w[i];
     
    half=(W+1)/2;
    for(long long int i=0;i<n;i++)
      { if(w[i]>=half && w[i]<=W)
           {flag=1; position=i+1; break; }
        else if(w[i]<half)   
          { sum+=w[i];
            pos[x]=i+1;
            x++;
            if(sum>=half)
               break;
          }
        
      }
    if(flag==1 )
      cout<<"1\n"<<position<<endl;
    else if(sum>=half) 
      { cout<<x<<endl;
        for(int i=0;i<x;i++)
           cout<<pos[i]<<" ";
        cout<<endl;   
      }
    else
       cout<<"-1\n";
  }
  return 0;  
}