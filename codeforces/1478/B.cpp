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
{   int t=1;
    cin>>t;
    while(t--)
    { int q,d,unit,tenth,temp;
      cin>>q>>d;
      lli a[q];
      for(int i=0;i<q;i++)
         cin>>a[i];
      
      for(int i=0;i<q;i++)
      { if(a[i]>=10 && a[i]<=99)
        { if(d==1)
          { cout<<"YES\n"; continue;} 
          unit=a[i]%10;
          tenth=a[i]/10;
          if(unit==d || tenth==d)
          { cout<<"YES\n"; continue;} 
          temp=0;
          if(tenth<d)
          { for(int z=1;z<=100;z++)
              if((z*d)%10==unit && (z*d)/10<=tenth)
              {  cout<<"YES\n"; break;}
              else if(z==100)
                cout<<"NO\n";
            continue;     
          }
          if(tenth>d)
          { if(a[i]-(10*d)>=d)
            { cout<<"YES\n"; continue; }
            for(int z=1;z<=100;z++)
              if((z*d)%10==unit && (z*d)/10<=tenth)
              {  cout<<"YES\n"; break;}
              else if(z==100)
                cout<<"NO\n";
            continue;   
              
          }
        }
        else if(a[i]>=100)
          cout<<"YES\n";
        else if(a[i]<=9)
        { if(a[i]%d==0)
            cout<<"YES\n";
          else
            cout<<"NO\n";
            
        }
      }
           
      
          
    }  
    
    return 0;  
}