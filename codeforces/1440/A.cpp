#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<ctype.h>
using namespace std;

int main()
{ int T;
  cin>>T;
  while(T--)
  { int n,c0,c1,h,count0=0,count1=0;
    cin>>n>>c0>>c1>>h;
    char s[n+1];
    cin>>s;
    for(int i=0;i<n;i++)
     if(s[i]=='1')
        count1++;
     else if(s[i]=='0')
        count0++;
    if(c0+h<c1)
       c1=c0+h;
    else if(c1+h<c0)   
       c0=c1+h;
    cout<<(count0*c0)+(count1*c1)<<endl;   
  }
  
  return 0;  
}