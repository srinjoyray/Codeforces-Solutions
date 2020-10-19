#include<iostream>
#include<algorithm>
using namespace std;

int func(long int n)
{ for(long int i=2;i*i<=n;i++)
      if(n%i==0)
         return i;
  return n;  
}
int main()
{ int T;
  cin>>T;
  while(T--)
  { long int n,k;
    cin>>n>>k;
    if(n%2==0)
      n=n+2*k;
    else
      n=n+func(n)+2*(k-1);
    cout<<n<<endl;  
  }
  
  
  return 0;  
}