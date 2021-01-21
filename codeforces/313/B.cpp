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
    { string s;
      cin>>s;
      int m,n;
      cin>>m;
      n=s.length();
      int prefix[n]={0};
      for(int i=1;i<n;i++)
      {  if(s[i]==s[i-1])
          { prefix[i]=prefix[i-1]+1;
            
            //cout<<"g"<<prefix[i]<<endl;
          }
         else
          prefix[i]=prefix[i-1];
      }       
      while(m--)
      { int l,r;
        cin>>l>>r;
        l--;r--;
        //cout<<prefix[l]<<" "<<prefix[r]<<" ";
        cout<<prefix[r]-prefix[l]<<endl;
          
      }
    }  
    
    return 0;  
}