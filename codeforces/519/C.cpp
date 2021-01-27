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
    //cin>>t;
    t=1; 
    while(t--)
    { int n,m,team;
      cin>>n>>m;
      team=(n+m)/3;
      team=std::min(team,n);
      team=std::min(team,m);
      cout<<team<<endl;
    }  
    
    return 0;  
}