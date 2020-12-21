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
{   int t;
    cin>>t;
    while(t--)
    { int n,count_r=0,count_b=0;
      cin>>n;
      string r,b;
      cin>>r>>b;
      for(int i=0;i<n;i++)
      { if(r[i]>b[i])
          count_r++;
        else if(r[i]<b[i])
          count_b++;
      }
      if(count_r>count_b)
        cout<<"RED\n";
      else if(count_b>count_r)
        cout<<"BLUE\n";
      else
        cout<<"EQUAL\n";
    }
    return 0;  
    
}