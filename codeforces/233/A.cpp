#include <bits/stdc++.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<ctype.h>
using namespace std;
 
int main()
{ int n;
  cin>>n;
  if(n%2==1)
    cout<<"-1";
  else
    for(int i=1;i<=n;i+=2)
      cout<<i+1<<" "<<i<<" ";
  return 0;  
}