#include <bits/stdc++.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<ctype.h>
#define lli long long int 
#define mod 1000003
#define pi 3.141592653589793238
using namespace std;
lli func(lli n)
{
    return (n*(n-1)*(n-2))/6; 
}
int main()
{ int t;
  cin>>t;
  while(t--)
  { lli n,count=0,temp;
    cin>>n;
    lli arr[n],freq[n+1]; 
    for(int i=1;i<=n;i++)
       freq[i]=0;
      
    for(int i=0;i<n;i++)
       { cin>>arr[i];
         freq[arr[i]]++;
       }
   
    for(int i=1;i<=n;i++)
    { lli group1=0,group2=0,group3=0;
     
      if(freq[i]==0)
         continue;
      
      if(freq[i]>=3)
         group3=func(freq[i]);
      if(i>=2)
      { if(freq[i]>=2 && freq[i-1]>=1)
          group2+=((freq[i]*(freq[i]-1))/2)*freq[i-1];
        if(freq[i]>=1 && freq[i-1]>=2)
          group2+=((freq[i-1]*(freq[i-1]-1))/2)*freq[i];
      }
      if(i>=3)
      { if(freq[i]>=2 && freq[i-2]>=1)
          group2+=((freq[i]*(freq[i]-1))/2)*freq[i-2];
        if(freq[i]>=1 && freq[i-2]>=2)
          group2+=((freq[i-2]*(freq[i-2]-1))/2)*freq[i];
        if(freq[i]>=1 && freq[i-1]>=1 && freq[i-2]>=1)
          group1+=freq[i]*freq[i-1]*freq[i-2];
          
      }
      temp=group1+group2+group3; 
      count+=temp; //cout<<group1<<" "<<group2<<" "<<group3<<" "<<count<<endl;
    }
    cout<<count<<endl;   
  }        
  return 0;  
 
}