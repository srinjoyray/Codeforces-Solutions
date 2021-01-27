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
{   int t;
    cin>>t;
    //t=1; 
    while(t--)
    { int n,k;
      cin>>n>>k;
      string s;
      cin>>s;
      int next[n],last=-1,count=0;
      for(int i=n-1;i>=0;i--)
      {  next[i]=last;
         if(s[i]=='1')
           last=i;
      }
     /* for(int i=0;i<n;i++)
        cout<<next[i]<<" ";
      cout<<endl;*/    
      for(int i=0;i<n;i++)
      { if(s[i]=='1')
        { i+=k; continue;}
        if(next[i]-i>k || next[i]==-1)
        { i+=k;
          count++;
        }
      }
      cout<<count<<endl;
    }  
    
    return 0;  
}