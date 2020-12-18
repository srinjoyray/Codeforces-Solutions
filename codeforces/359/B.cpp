#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<ctype.h>
#define lli long long int 
#define mod 1000003
#define pi 3.141592653589793238
using namespace std;
 
int main()
{ int n,k;
  cin>>n>>k;
  n*=2; k*=2;
  int arr[n+1],temp;
  for(int i=1;i<=n;i++)
     arr[i]=i;
  for(int i=1;i<k;i+=2)
  { temp=arr[i];
    arr[i]=arr[i+1];
    arr[i+1]=temp;
  }
  for(int i=1;i<=n;i++)
    cout<<arr[i]<<" ";
  return 0;  
}