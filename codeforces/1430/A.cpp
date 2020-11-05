#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

int main()
{ int T;
  cin>>T;
  while(T--)
  { int n;
    cin>>n;
    if(n==4 || n<3)
       cout<<"-1\n";
    else if(n%3==0)
       cout<<n/3<<" 0 0\n";
    else if(n%3==2)
       cout<<n/3-1<<" 1 0\n";
    else if(n%3==1)
       cout<<n/3-2<<" 0 1\n";
      
  }
  return 0;  
}