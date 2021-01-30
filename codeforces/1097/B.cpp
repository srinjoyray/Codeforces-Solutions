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
    //cin>>t;
    while(t--)
    { int n;
      cin>>n;
      lli a[n],sum=0,temp,flag=0;
      for(int i=0;i<n;i++)
      {  cin>>a[i];
         sum+=a[i];
      } //cout<<sum<<endl;
      if(sum%2)
      { cout<<"NO\n"; continue;}
      
      bool dp[n+1][sum+1];
      for(int j=0;j<sum+1;j++)
         dp[0][j]=0;
      for(int i=0;i<n+1;i++)
         dp[i][0]=1;
         
      for(int i=1;i<n+1;i++)
        for(int j=1;j<sum+1;j++)
           { if(j<a[i-1])
               dp[i][j]=dp[i-1][j];
             else
               dp[i][j]=(dp[i-1][j]||dp[i-1][j-a[i-1]]);
           }
     /* for(int i=0;i<n+1;i++)
      {  for(int j=0;j<sum+1;j++)
            cout<<dp[i][j]<<" ";
         cout<<endl;
      } */    
      temp=sum/2;
      while(temp<=sum)
      { //cout<<temp<<endl;
        if(dp[n][temp]==1)
          { flag=1;break;}
        temp+=180;
        
      }
      if(flag==1)
        cout<<"YES\n";
      else
        cout<<"NO\n";
    }  
    
    return 0;  
}