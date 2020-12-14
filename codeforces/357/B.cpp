#include <bits/stdc++.h>
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
{ int n,m;
  cin>>n>>m;
  int arr[m][3],colour[n+1]={0};
  for(int i=0;i<m;i++)
     for(int j=0;j<3;j++)
         cin>>arr[i][j];
  for(int i=0;i<m;i++)
    { int col[4]={0};
      for(int j=0;j<3;j++)
         { if(colour[arr[i][j]]>0)
             col[colour[arr[i][j]]]=1;
         }     
      for(int j=0;j<3;j++)    
         { if(colour[arr[i][j]]==0)    
             { if(col[1]==0)
                 {col[1]=1;colour[arr[i][j]]=1;}
               else if(col[2]==0)
                 {col[2]=1;colour[arr[i][j]]=2;}
               else if(col[3]==0)
                 {col[3]=1;colour[arr[i][j]]=3;}
             }
         }
    }
  for(int i=1;i<=n;i++)
    cout<<colour[i]<<" ";
  return 0;  
}