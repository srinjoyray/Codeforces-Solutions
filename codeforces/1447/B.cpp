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
  { int n,m;
    cin>>n>>m;
    int arr[m][n],sum=0,count=0,min;
    for(int i=0;i<m;i++)
       for(int j=0;j<n;j++)
          {  cin>>arr[i][j];
             sum+=abs(arr[i][j]);
             if(i==0 && j==0)
                min=abs(arr[i][j]);
             else if(abs(arr[i][j])<min)
                min=abs(arr[i][j]);    
             if(arr[i][j]<0)
                count++;
             
          }
    if(count%2==1)
      sum=sum-(2*min);
    cout<<sum<<endl;  
  }
  
  return 0;  
}