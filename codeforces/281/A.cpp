#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<ctype.h>
using namespace std;

int main()
{ char S[1000];
  cin>>S;
  for(int i=0;i<strlen(S);i++)
  { if(i==0)
      S[i]=toupper(S[i]);
    else if(S[i-1]==' ')
      S[i]=toupper(S[i]);
      
  }
  cout<<S;
  return 0;  
}