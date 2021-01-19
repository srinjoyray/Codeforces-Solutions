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
      int w[n],max=0;
      for(int i=0;i<n;i++)
         cin>>w[i];
      sort(w,w+n);
      for(int sum=2;sum<=2*n;sum++)
      { int i=0,j=n-1,count=0;
        while(i<j) 
        { if(w[i]+w[j]==sum)
            { count++; i++; j--;}
          else if(w[i]+w[j]>sum)
            j--;
          else if(w[i]+w[j]<sum)
            i++;
        }
        max=std::max(max,count);
        
      }
    
     cout<<max<<endl; 
    }  
    
    return 0;  
}