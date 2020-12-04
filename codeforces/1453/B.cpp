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
  { long long n,temp,sum=0,diff,max_diff;
    cin>>n;
    vector<long> a;
    for(int i=0;i<n;i++)
      { cin>>temp;
        a.push_back(temp);
      }
      
    for(int i=1;i<n;i++)
       sum+=abs(a[i]-a[i-1]);
    
    max_diff=max(abs(a[1]-a[0]),abs(a[n-1]-a[n-2]));
    for(int i=1;i<n-1;i++)
      { diff=abs(a[i]-a[i-1])+abs(a[i+1]-a[i])-abs(a[i+1]-a[i-1]);
        max_diff=max(max_diff,diff);  
          
      }
    sum=sum-max_diff;
    cout<<sum<<endl;
  }
 
  return 0;  
}