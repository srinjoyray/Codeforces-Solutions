#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

int main()
{ int T;
  cin>>T;
  while(T--)
  { int x,n,mod,digit,total=0;
    cin>>x;
    digit=x%10;
    while(x)
    { total++;
      x=x/10;        
    }
    x=(digit-1)*4+total; 
    n=x/4;
    mod=x%4;
    if(mod==2)
      mod=3;
    else if(mod==3)
      mod=6;
    cout<<n*10+mod<<endl;
  }
  return 0;  
}