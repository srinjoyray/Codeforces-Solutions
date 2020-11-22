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
  { long int n,count=0;
    cin>>n;
    if(n<=3)
       count=n-1;
    else if(n%2==0)
       count=2;
    else
       count=3;
    cout<<count<<endl;
  }
  return 0;  
}