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
{ int n,k;
  cin>>n>>k;
  int arr[n],col[n][k],temp,flag=0,num,max,min;
  for(int i=0;i<n;i++)
     cin>>arr[i]; 
  for(int i=0;i<n;i++)     
    for(int j=0;j<k;j++)
       col[i][j]=0;
       
  max=arr[0];min=arr[0];
  for(int i=0;i<n;i++)
    { max=std::max(max,arr[i]);
      min=std::min(min,arr[i]);
    }
       
  for(int i=0;i<n;i++)
   {  temp=arr[i]; 
      num=temp/k;
      temp=temp%k;
      for(int j=0;j<temp;j++)
            { col[i][j]=num+1;
              
            }
          for(int j=temp;j<k;j++)
            { col[i][j]=num;
              
            }
       
    
   }
  if(max-min>k) 
    flag=1;
  if(flag==1)
    cout<<"NO";
  else
    { cout<<"YES\n";
      for(int i=0;i<n;i++)
       { for(int j=0;j<k;j++)
          {  if(col[i][j]>0)
               { for(int k=1;k<=col[i][j];k++)
                   cout<<j+1<<" ";
               }
             else
                break;
          }
         cout<<endl; 
       }      
    }
  return 0;  
}