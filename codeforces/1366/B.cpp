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
    { lli n,m,x,left,right;
      cin>>n>>x>>m;
      left=x;
      right=x;
      while(m--)
      { lli l,r;
        cin>>l>>r;
        if(right>=l && left<=r)
          { left=std::min(left,l);
            right=std::max(right,r);  
          }
          
      }
      cout<<right-left+1<<endl;
    }  
    
    return 0;  
}