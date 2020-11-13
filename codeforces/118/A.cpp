#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<ctype.h>
using namespace std;

int main()
{ char str[100],ans[200];
  cin>>str;
  int start=0;
  int len=strlen(str);
  for(int i=0;i<len;i++)
  { str[i]=tolower(str[i]);
    if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u' || str[i]=='y')  
      continue;
    else
     { ans[start]='.';
       ans[start+1]=str[i];
       start+=2;
     }
     
  }
  for(int i=0;i<start;i++)
    cout<<ans[i];
  return 0;  
}