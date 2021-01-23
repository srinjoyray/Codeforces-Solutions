#include <bits/stdc++.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<ctype.h>
#define lli long long int 
#define mod 1000000007
#define pi 3.141592653589793238
using namespace std;

int main()
{   int t;
    cin>>t;
    //t=1; 
    while(t--)
    { lli temp;
      int a[9][9];
      for(int i=0,j;i<9;i++)
      { cin>>temp;
        j=8;
        while(temp && j>=0)
        { 
          a[i][j]=temp%10;
          if(a[i][j]==1)
            a[i][j]=2;
          temp/=10;
          j--;
        }
      }    
      for(int i=0;i<9;i++)
        { for(int j=0;j<9;j++)
            cout<<a[i][j];
          cout<<endl;
        }    
    }  
    
    return 0;  
}