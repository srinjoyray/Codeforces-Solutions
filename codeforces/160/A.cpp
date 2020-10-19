#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

int main()
{ int n,sum=0,temp,i;
  cin>>n;
  int arr[n];
  for(i=0;i<n;i++)
  { cin>>arr[i];
    sum+=arr[i];  
  }
  sort(arr,arr+n,greater<int>());
  for(i=0;i<n;i++)
  { temp+=arr[i];
    if(temp>sum-temp)
        break;
  }
  cout<<i+1;
  return 0;  
}