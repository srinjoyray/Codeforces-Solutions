#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

int main()
{ int n,m,temp,min;
  cin>>n>>m;
  int arr[m];
  for(int i=0;i<m;i++)
    cin>>arr[i];
  sort(arr,arr+m); 
  min=arr[n-1]-arr[0]; 
  for(int i=1;i<=m-n;i++)
  { temp=arr[n-1+i]-arr[i];
    if(min>temp)
        min=temp;
  }
  cout<<min<<endl;
  return 0;  
}