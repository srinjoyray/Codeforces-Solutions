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
int dp[3002][3002];

int main()
{   int t;
    cin>>t;
    //t=1; 
    while(t--)
    { int n;
      cin>>n;
      int a[n],count=0,last=-1,temp;
      string b;
      cin>>b; 
      for(int i=0;i<n;i++)
       { temp=b[i]-'0'; //cout<<temp<<endl;
         if(last!=2 && temp==1)
          { a[i]=1; last=2;}
         else if(temp==1)
          { a[i]=0; last=1;}
         else if(temp==0 && last!=1)
          { a[i]=1; last=1;}
         else 
          { a[i]=0; last=0;}
       } 
      for(int i=0;i<n;i++)
        cout<<a[i];
      cout<<endl;    
    }  
    
    return 0;  
}