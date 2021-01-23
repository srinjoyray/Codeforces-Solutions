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
bool comp(pair<int,int> &a,pair<int,int> &b)
{ if(a.first==b.first)
    return(a.second<b.second);
  return(a.first<b.first);     
}
int main()
{   int t;
    cin>>t;
    //t=1; 
    while(t--)
    { int n;
      cin>>n;
      int a[n],even=0,flag=1;
      for(int i=0;i<n;i++)
         cin>>a[i];
      if(n%2==1)
      { cout<<"NO\n";
        continue;  
      }
      sort(a,a+n);
      for(int i=0;i<n;i++)
      { if(a[i]%2==0)
          even++;
        if(i!=0 && a[i]-a[i-1]==1)
          flag=0;
      }
      if(even%2==1 && flag==1)
         cout<<"NO\n";
      else
        cout<<"YES\n";
    }  
    
    return 0;  
}