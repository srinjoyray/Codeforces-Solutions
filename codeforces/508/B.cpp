#include <bits/stdc++.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<ctype.h>
#define lli long long int 
using namespace std;

int main()
{ string s;
  char s_temp;
  int digit,last,last_even=-1,flag=0,n;
  cin>>s;
  n=s.size();
  last=(s[n-1]-'0');
  for(int i=0;i<n-1;i++)
   { digit=(s[i]-'0');
     if(digit%2==0 && digit<last)
       { s_temp=s[i];
         s[i]=s[n-1];
         s[n-1]=s_temp;
         flag=1;
         break;
       }
     else if(digit%2==0)
       last_even=i;
   }
 if(flag==0 && last_even>-1 )
  { s_temp=s[last_even];
    s[last_even]=s[n-1];
    s[n-1]=s_temp;
    flag=1;
  }
 if(last_even==-1 && flag==0)
   cout<<"-1";
 else
   cout<<s;
       
   
 return 0;  
}