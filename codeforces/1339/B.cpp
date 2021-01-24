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
    { int n;
      cin>>n;
      lli a[n];
      for(int i=0;i<n;i++)
        cin>>a[i];
      sort(a,a+n);
      vector<lli> v;
      int i=0,j=n-1;
      while(i<=j)
      { if(i==j)
          v.push_back(a[i]);
        else
        { v.push_back(a[i]);
          v.push_back(a[j]);        
        }
        i++;
        j--;
      }
      reverse(v.begin(),v.end());
      for(int k=0;k<v.size();k++)
         cout<<v[k]<<" ";
      cout<<endl;     
    }  
    
    return 0;  
}