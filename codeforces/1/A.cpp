#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<ctype.h>
using namespace std;

int main()
{ long long int n,m,a;
  cin>>n>>m>>a;
  n=n+a-1;
  m=m+a-1;
  cout<<(n/a)*(m/a)<<endl;
  return 0;  
}