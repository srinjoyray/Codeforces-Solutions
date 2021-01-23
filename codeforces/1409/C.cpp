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
    { int n,x,y,diff,start,count;
      cin>>n>>x>>y;
      diff=y-x;
      vector<int> v;
      for(int i=1;i<=diff;i++)
      { if(diff%i==0 && (diff/i)+1<=n)
          {   start=y;
              count=0;
              while(start>0 && count<n)
              { v.push_back(start);
                start-=i;
                count++;
              }
              while(count<n)
              { y+=i;
                v.push_back(y);
                count++;  
              }
              break;
          }
      }
      sort(v.begin(),v.end());
      for(int i=0;i<v.size();i++)
         cout<<v[i]<<" ";
      cout<<endl;      
    }  
    
    return 0;  
}