#include <bits/stdc++.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<ctype.h>
using namespace std;
 
int main()
{ int t;
  cin>>t;
  while(t--)
  { int n;
    cin>>n;
    for(int i=1;i<=n;i++)
       if(i==n)
         cout<<"1 ";
       else
         cout<<i+1<<" ";
    cout<<endl;     
  }
  return 0;  
}