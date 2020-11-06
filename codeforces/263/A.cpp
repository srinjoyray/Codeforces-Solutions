#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<ctype.h>
using namespace std;

int main()
{ int arr[6][6],x,y;
  for(int i=1;i<=5;i++)
     for(int j=1;j<=5;j++)
     {  cin>>arr[i][j];
        if(arr[i][j]==1)
          { x=i;y=j;break;}
     }
  x=max(x-3,3-x);
  y=max(3-y,y-3);
  cout<<x+y<<endl;
  return 0;  
}