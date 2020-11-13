#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<ctype.h>
using namespace std;

int main()
{ char s[100];
  cin>>s;
  int len,flag=0;
  len=strlen(s);
  for(int i=0;i<len;i++)
  { if(flag==0 && s[i]=='h')
       flag=1;
    else if(flag==1 && s[i]=='e')
       flag=2;
    else if(flag==2 && s[i]=='l')
       flag=3;
    else if(flag==3 && s[i]=='l')
       flag=4;
    else if(flag==4 && s[i]=='o')
       {flag=5;break;}
  }
  if(flag==5)
    cout<<"YES\n";
  else
    cout<<"NO\n";
  return 0;  
}