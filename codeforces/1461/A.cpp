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
    { int n,k,num,last;
      cin>>n>>k;
      char ch='a';
      num=(n+k-1)/k;
      last=n%k;
      if(last==0)
        last=k;
      for(int i=1;i<=num;i++)
      { if(i!=num)
          { for(int j=1;j<=k;j++)
              cout<<ch;
          }
        else
          { for(int j=1;j<=last;j++)
              cout<<ch;
          }
        ch++;
        if(ch=='d')
          ch='a';
      }
      cout<<endl;
      
    }  
    
    return 0;  
}