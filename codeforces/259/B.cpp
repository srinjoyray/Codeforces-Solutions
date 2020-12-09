#include <bits/stdc++.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<ctype.h>
#define lli long long int 
#define mod 1000000007
using namespace std;

int main()
{ lli arr[3][3],a,b,c,diag,row1,row2,row3,up,down,x;
  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
       cin>>arr[i][j];
  row1=arr[0][1]+arr[0][2];
  row2=arr[1][0]+arr[1][2];
  row3=arr[2][0]+arr[2][1];
  up=row2-row1;
  down=row2-row3;
  diag=arr[2][0]+arr[0][2];
  x=(diag-up-down)/2;
  arr[1][1]=x;
  arr[0][0]=x+up;
  arr[2][2]=x+down;
  for(int i=0;i<3;i++)
    { for(int j=0;j<3;j++)
        cout<<arr[i][j]<<" ";
      cout<<endl;
    }  
  return 0;  
}