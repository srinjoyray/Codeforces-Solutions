#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

int main()
{ int n,x;
  cin>>n;
  char s[n],ans[n];
  cin>>s;
  if(n%2==1)
    for(int i=0,x=0;i<n;i++)
     { if(i%2==0)
         {ans[n/2+x]=s[i];x++;}
       else
          ans[n/2-x]=s[i];
     }
  else
    for(int i=0,x=1;i<n;i++)
      { if(i%2==0)
          {ans[n/2-x]=s[i];}
        else
          {ans[n/2+x-1]=s[i];x++;}
      }
    
    
  for(int i=0;i<n;i++)
      cout<<ans[i];
  return 0;  
}