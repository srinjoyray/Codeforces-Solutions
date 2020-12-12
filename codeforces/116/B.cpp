#include <bits/stdc++.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<ctype.h>
#define lli long long int 
#define mod 1000000007
using namespace std;
#define pi 3.141592653589793238

int main()
{ int n,m,count=0,total=0;
  cin>>n>>m;
  char s[n][m];
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
        cin>>s[i][j]; 
          
  for(int i=0;i<n;i++)
    { 
      for(int j=0;j<m;j++)
      { count=0;
        if(s[i][j]=='P')
          { if(i>0 && s[i-1][j]=='W')
             {count++;s[i-1][j]='.';}
            else if(j>0 && s[i][j-1]=='W')
             {count++;s[i][j-1]='.';}
            else if(j<m-1 && s[i][j+1]=='W')
             {count++;s[i][j+1]='.';}
            else if(i<n-1 && s[i+1][j]=='W')
             {count++;s[i+1][j]='.';}
            
            
          }
        /*if(count==1)
          cout<<i<<" "<<j<<endl;*/
        total+=count;  
      }
    }  
  cout<<total<<endl;    
  return 0;  
}