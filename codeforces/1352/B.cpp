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
    { lli n,k;
      cin>>n>>k;
      if(n%2==1 && k%2==0)
      { cout<<"NO\n";
        continue;  
      }
      else if(n<k || (n>k && n<2*k && (n-k)%2==1))
      { cout<<"NO\n";
        continue;  
      }
      cout<<"YES\n";
      if(n==k)
      { for(int i=1;i<=k;i++)
          cout<<"1 ";
        cout<<endl;
        continue;
      }
      if(n<2*k || n%2==1)
      { for(int i=1;i<=k;i++)
          if(i!=k)
           { cout<<"1 ";n-=1;}
          else
             cout<<n;
        cout<<endl;     
          
      }
      else if(n%2==0)
      { for(int i=1;i<=k;i++)
          if(i!=k)
           {cout<<"2 "; n-=2;}
          else
           cout<<n;
        cout<<endl;   
      }
      
    }  
    
    return 0;  
}