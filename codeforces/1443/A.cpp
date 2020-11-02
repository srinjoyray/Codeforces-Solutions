#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

int main()
{ int t;
  cin>>t;
  while(t--)
  { int n,z;
    cin>>n;
    z=n*4;
    while(n--)
    { cout<<z<<" ";
      z-=2;    
    }
    cout<<endl;  
  }
  return 0;  
}