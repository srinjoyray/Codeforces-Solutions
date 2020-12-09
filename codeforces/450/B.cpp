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
{ long long int x,y,n;
  cin>>x>>y>>n;
  x=(x+mod)%mod; y=(y+mod)%mod;
  switch(n%6)
  { case 0 : {cout<<((x-y+mod)%mod);break;}
    case 1 : {cout<<x%mod;break;} 
    case 2 : {cout<<y%mod;break;}
    case 3 : {cout<<((y-x+mod)%mod);break;}
    case 4 : {cout<<((-x+mod)%mod);break;}
    case 5 : {cout<<((-y+mod)%mod);break;}  
  }
  return 0;  
}