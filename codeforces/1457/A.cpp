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
  { long n,m,r,c,ans;
    cin>>n>>m>>r>>c;
    ans=((std::max(r-1,n-r)) + (std::max(c-1,m-c)));
    cout<<ans<<endl;
      
  }
  return 0;  
}