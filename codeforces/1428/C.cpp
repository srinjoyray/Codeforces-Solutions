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
    { string s;
      cin>>s;
      int n,ans=0,store=1,temp;
      n=s.size();
      for(int i=n-1;i>=0;i--)
         if(s[i]=='B')
          { s=s.substr(0,i+1);
            break;
          }     
       
      ans=n-s.size();  
      //cout<<s<<" "<<ans<<endl;     
      n=s.size();
      temp=n;
      for(int i=1;i<n;i++)
      { if(s[i]=='A')
          store++;
        else if(s[i]=='B')
        { if(store==0)
            store++;
          else
           { store--;
             temp-=2;  
           }
        }  
      }
      ans+=temp;
      cout<<ans<<endl;
    }  
    
    return 0;  
}