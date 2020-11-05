#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

int main()
{ int T;
  cin>>T;
  while(T--)
  { int a,b,c,d;
    cin>>a>>b>>c>>d;
    cout<<max(a+b,c+d)<<endl;
      
  }
  return 0;  
}