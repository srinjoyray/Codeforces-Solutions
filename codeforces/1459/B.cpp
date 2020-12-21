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

int main()
{   int n,step,step_x,step_y,pos;
    cin>>n;
    if(n%2==0)
    { step=n/2;
      pos=step+1;
      cout<<pos*pos;
      return 0;
    }
    else
    { step_x=n/2;
      step_y=(n+1)/2;
      pos=(step_x+1)*(step_y+1);
      cout<<2*pos; 
    }
    return 0;  
    
}