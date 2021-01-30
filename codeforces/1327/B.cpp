#include <bits/stdc++.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<ctype.h>
#define lli long long int 
#define mod 1000000007
#define pi 3.141592653589793238
using namespace std;

int main()
{   int t=1;
    cin>>t; //cout<<t;
    while(t--)
    { int n,temp;
      cin>>n;
      temp=1;
      int taken[n+1]={0},pos=-1;
      
      while(temp<=n)
      { 
        int k;
        cin>>k;
        if(k==0 && pos==-1)
          pos=temp;
        int a[k];
        for(int i=0;i<k;i++)
           cin>>a[i];
        for(int i=0;i<k;i++)
        { 
          if(taken[a[i]]==0)
            { taken[a[i]]=1;
              //cout<<a[i]<<" ";
              break;
            }
          else if(i==k-1 && pos==-1)
            pos=temp;
        }  
        temp++;
      }//cout<<"#";
      
         
      if(pos==-1)
      { cout<<"OPTIMAL\n";
        continue;
      }    
      cout<<"IMPROVE\n";
      cout<<pos<<" ";
      for(int i=1;i<n+1;i++)
         if(taken[i]==0)
         { cout<<i<<endl;
           break;
         }
    }  
    
    return 0;  
}