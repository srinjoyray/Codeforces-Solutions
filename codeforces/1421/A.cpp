#include <iostream>
using namespace std;
 
int findx(long int a, long int b)
{ int i=0,x=0;
  while(a||b)
    { if((a&1)&&(b&1)==1)
         x+=(1<<i);
      a>>=1;
      b>>=1;
      i++;
    }
  return x;  
}
 
int main(){
    int T;
    cin>>T;
    while(T--)
    { long int a,b,x,min;
      cin>>a>>b;
      x=findx(a,b);
      min=(a^x)+(b^x);
      cout<<min<<endl;    
    }
    
    
}