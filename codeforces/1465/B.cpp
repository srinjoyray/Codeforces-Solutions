#include <bits/stdc++.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<ctype.h>
#define lli long long int 
#define mod 1000003
#define pi 3.141592653589793238
using namespace std;
bool fair(lli x)
{ int digit;
  lli temp;
  temp=x;
  while(temp)
  { digit=temp%10;
    temp/=10;
    if(digit==0)
      continue;
    if(x%digit!=0)
       return false;
      
  }    
  return true;
}

int main()
{   int t;
    cin>>t;
    while(t--)
    { lli n;
      cin>>n; 
      while(true)
      { if(fair(n))
          break;
        n++;
    
      }
      cout<<n<<endl;
    }
    return 0;  
    
}