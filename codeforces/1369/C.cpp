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
    cin>>t;
    while(t--)
    { int n,k;
      cin>>n>>k;
      lli a[n],w[k],ans=0,count=0;
      vector<lli> v;
      for(int i=0;i<n;i++)
         cin>>a[i];
      for(int i=0;i<k;i++)
         cin>>w[i];
      sort(a,a+n,greater<int>());     
      for(int i=0;i<k;i++)
        { if(w[i]==1)
           count++;
          else
           v.push_back(w[i]); 
        }   
      for(int i=0;i<count;i++)
        ans+=2*a[i];
      sort(v.begin(),v.end(),greater<lli>());    
      k-=count;    
      for(int i=count,temp=0;temp<k;temp++,i++)
        ans+=a[i];
      for(int i=n-1,temp=0;temp<k;temp++)
      {  ans+=a[i];
         i-=v[0]-1;
         v.erase(v.begin());
      }
      cout<<ans<<endl;    
    }  
    
    return 0;  
}