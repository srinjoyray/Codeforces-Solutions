#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

int main()
{ char p[101];
  int len,flag=0;
  cin>>p; 
  len=strlen(p);
  for(int i=0;i<len;i++)
     { if(p[i]=='H' || p[i]=='Q' || p[i]=='9' )
         {flag=1;break;}
     }
  if(flag==1)
     cout<<"YES\n";
  else
     cout<<"NO\n";
  return 0;  
}