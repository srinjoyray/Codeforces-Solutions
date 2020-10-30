#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

int main()
{ int n,l,r,min,max;
  cin>>n>>l>>r;
  min=(pow(2,l)-1)+(n-l);
  max=(pow(2,r)-1)+(n-r)*(pow(2,r-1));
  cout<<min<<" "<<max<<endl;
  return 0;  
}