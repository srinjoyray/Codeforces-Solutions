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
  { int n,m;
    cin>>n;
    m=n;  
    cout<<m<<endl;
    for(int i=1;i<=n;i++)
       cout<<i<<" ";
    cout<<endl;   
  }
  
  return 0;  
}