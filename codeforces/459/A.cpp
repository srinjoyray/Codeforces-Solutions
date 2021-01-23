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
    { int x1,y1,x2,y2,dist;
      cin>>x1>>y1>>x2>>y2;
      int flag=0;
      if(x2==x1 || y2==y1)
        flag=1;
      if(abs(x2-x1)==abs(y2-y1))
        flag=2;
      if(flag==0)
      { cout<<"-1\n";
        continue;  
      } 
      if(flag==1)
      { if(x1==x2)
        { dist=abs(y1-y2);
          cout<<x1+dist<<" "<<y1<<" ";
          cout<<x2+dist<<" "<<y2<<" ";
        }  
        else if(y1==y2)
        { dist=abs(x1-x2);
          cout<<x1<<" "<<y1+dist<<" ";
          cout<<x2<<" "<<y2+dist<<" ";
        }
      }
      else if(flag==2)
      { cout<<x1<<" "<<y2<<" ";
        cout<<x2<<" "<<y1<<" ";  
      }
      
    }  
    
    return 0;  
}