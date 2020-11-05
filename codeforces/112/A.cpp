#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<ctype.h>
using namespace std;

int main()
{ char a[101],b[101];
  cin>>a>>b;
  int len=strlen(a);
  for(int i=0;i<len;i++)
  { a[i]=tolower(a[i]);
    b[i]=tolower(b[i]);  
  }
  cout<<strcmp(a,b)<<endl;
  return 0;  
}