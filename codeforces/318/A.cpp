#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

int main()
{ long long int n,k,mid;
  cin>>n>>k;
  mid=(n+1)/2;
  if(k<=mid)
     cout<<(2*k)-1;
  else
     cout<<(k-mid)*2;
  return 0;  
}