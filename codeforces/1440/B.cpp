#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<ctype.h>
using namespace std;

int main()
{ int T;
  cin>>T;
  while(T--)
  { int n,k,gap;
    cin>>n>>k;
    long int a[n*k];
    long long int sum=0;
    for(int i=0;i<n*k;i++)
       cin>>a[i];
    gap=n/2;
    for(int i=n*k-1-gap,count=1; i>=0,count<=k; count++,i=i-gap-1)
        sum+=a[i];
    cout<<sum<<endl;    
  }
  
  return 0;  
}