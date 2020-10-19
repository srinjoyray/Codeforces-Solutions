#include<iostream>
#include<algorithm>
using namespace std;

int main()
{ int T;
  cin>>T;
  while(T--)
  { int a1,b1,a2,b2;
    cin>>a1>>b1;
    cin>>a2>>b2;
    if(a1==a2 && b1+b2==a1)
       cout<<"Yes\n";
    else if (a1==b2 && a2+b1==a1)
             cout<<"Yes\n";
    else if(b1==a2 && a1+b2==b1)
             cout<<"Yes\n";
    else if(b1==b2 && a1+a2==b1)
             cout<<"Yes\n";
    else 
       cout<<"No\n";
      
  }
  
  
  return 0;  
}