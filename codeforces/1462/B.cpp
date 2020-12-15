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
{ int t;
  cin>>t;
  while(t--)
  { int n,count=0,flag=0,temp=0,max=0;
    cin>>n;
    string s;
    cin>>s;
    
    if(s[0]=='2')
     {  count++;
        if(s[1]=='0')
         {  count++;
           if( s[2]=='2')
             {  count++;
              if(s[3]=='0')
                count++;
             }
         }     
    }
    
     
      if(s[n-1]=='0')
        { temp++;
            if(s[n-1-1]=='2')
              {  temp++;
                 if(s[n-1-2]=='0')
                   { temp++;
                     if(s[n-1-3]=='2') 
                        temp++;  
                   }
              }
        }
      
    if(temp+count>=4)
       cout<<"YES\n";
    else
      cout<<"NO\n";
  }        
  return 0;  
 
}