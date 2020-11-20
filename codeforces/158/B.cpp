#include <bits/stdc++.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<ctype.h>
using namespace std;
 
int main()
{ int n;
  cin>>n;
  int s[n],one=0,two=0,three=0,four=0,count=0;
  for(int i=0;i<n;i++)
    {  cin>>s[i];
       if(s[i]==1)
          one++;
       else if(s[i]==2)
          two++;
       else if(s[i]==3)
          three++;
       else if(s[i]==4)
          four++;
    }
  count+=four; 
  if(three>=one)
   { count+=three;
     one=0;
   }
  else
   { count+=three;
     one=one-three;  
   }   
  count+=two/2;  
  two=two%2; 
  if(two==0)
   { count+=one/4;
     if(one%4!=0)
       count++;
   }  
  else
   { one+=2;
     count+=one/4; 
     if(one%4!=0)
       count++;
   } 
  cout<<count;
  return 0;  
}