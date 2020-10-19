#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

int main()
{ int len,count=1,flag=0;
  char str[101];
  cin>>str;
  len=strlen(str);
  for(int i=1;i<len;i++)
      { if(str[i]==str[i-1])
             count++;
        else
           count=1;
        if(count>=7)
           {flag=1;break;}
           
     }
  if(flag==0)
     cout<<"NO\n";
  else
     cout<<"YES\n";
  
  return 0;  
}