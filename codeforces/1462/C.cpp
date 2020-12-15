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
  { int x,digit,sum=0,num,req,put=9,store,count=0;
    cin>>x;
    if(x>45)
     {cout<<"-1"<<endl;continue;}
    for(int i=9;i>=0;i--)
    { sum+=i;
      count++;
     
      if(sum>=x)    
        {digit=count;break;}
    } //cout<<digit<<endl;
    string s;
    for(int i=0;i<digit;i++)
      s.push_back('0'+i+1); 
    sum=0;  
    for(int i=0;i<digit;i++)
      sum+=s[i]-'0';
    req=x-sum; 
    for(int i=digit-1;i>=0;i--)
    { 
      if(s[i]-'0'+req<put)
      { s[i]+=req;
        break;  
      }
      else  
      { store=s[i]-'0';
        s[i]='0'+put; 
       req=req-(put-store); put--;  
      }
      
     // cout<<req<<endl;  
    }
    cout<<s<<endl;
  }        
  return 0;  
 
}