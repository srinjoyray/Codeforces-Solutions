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
{ int m,n;
  cin>>m>>n;
  int arr[m][n],ans[m][n],copy[m][n],temp[m][n]={0},flag=0;
  for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
      cin>>arr[i][j]; 
  for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)  
        ans[i][j]=1;
  for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
      { if(arr[i][j]==0)
          { for(int x=0;x<m;x++)
                ans[x][j]=0;
            for(int x=0;x<n;x++)
                ans[i][x]=0;
          } 
      }
    for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)   
      temp[i][j]=0;
  ////////////////////////    
 /* for(int i=0;i<m;i++)
    {for(int j=0;j<n;j++)        
        cout<<ans[i][j]<<" ";
     cout<<endl;
    }*/   
      
  for(int i=0;i<m;i++) 
    for(int j=0;j<n;j++)
       copy[i][j]=ans[i][j];
  
   
       
  for(int i=0;i<m;i++)
   { flag=0;
     for(int j=0;j<n;j++)
         if(ans[i][j]==1)
           {flag=1;break;}
     if(flag==1)
       { for(int j=0;j<n;j++)
            temp[i][j]=1;
       }
   }
  
  for(int j=0;j<n;j++)
   { flag=0;
     for(int i=0;i<m;i++)
        if(ans[i][j]==1)
          {flag=1;break;}
     if(flag==1)
      { for(int i=0;i<m;i++)
          temp[i][j]=1;
      }  
   } 
  ////////////////////// 
  /*for(int i=0;i<m;i++)
    {for(int j=0;j<n;j++)        
        cout<<ans[i][j]<<" ";
     cout<<endl;
    }*/  
   
   
  flag=0;
  for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
      if(arr[i][j]!=temp[i][j])
        {flag=1;break;}
  /////////////////      
 /* for(int i=0;i<m;i++)
    {for(int j=0;j<n;j++)        
        cout<<arr[i][j]<<" ";
     cout<<endl;
    } */
  if(flag==1)
    cout<<"NO";
  else
    { cout<<"YES\n";
      for(int i=0;i<m;i++)
      { for(int j=0;j<n;j++)
            cout<<copy[i][j]<<" ";
        cout<<endl;
      }  
    }
  return 0;  
}