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
{ lli n,digit=0,temp,no,flag=0,num;
  string ans,alt;
  cin>>n;
  temp=n;
  while(temp)
  { digit++;
    temp/=10;  
  }
  no=(digit+1)/2;
  for(int i=1;i<=no;i++)
    ans.push_back('4');
  for(int i=1;i<=no;i++)
    ans.push_back('7');
  for(int i=1;i<=no+1;i++)
    alt.push_back('4');
  for(int i=1;i<=no+1;i++)
    alt.push_back('7');  
  do{ num=stoll(ans);
      if(num>=n)
        {flag=1;break;}
  }while(next_permutation(ans.begin(),ans.end()));   
  if(flag==1)
    cout<<ans;
  else
    cout<<alt;
  return 0;  
}