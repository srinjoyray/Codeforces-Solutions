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
  { int n,p,k,x,y;
    cin>>n>>p>>k;
    string s;
    cin>>s;
    cin>>x>>y;
    
    p--;
    int min=INT_MAX,temp=0,rem=0,end;
    int cumulative[n];
    for(int i=0;i<k;i++)
      { temp=0;
        for(int j=i;j<n;j+=k)
         { if(s[j]=='0')
             temp++;
           cumulative[j]=temp;  
         }
        
      }
    
    
    while(p<n)
    { temp=0;
      end=n-((n-1-p)%k)-1;
      temp=(cumulative[end]-cumulative[p]);
      if(s[p]=='0')
        temp++;
      temp*=x;        
      temp+=rem;   
      min=std::min(min,temp);
      rem+=y;
      p++;
    }
    cout<<min<<endl;
  }
  return 0;  
}