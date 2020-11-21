#include <bits/stdc++.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<ctype.h>
using namespace std;
 
int main()
{ long int n,start=1,flag=0,size=5,no;
  cin>>n;
  while(start+size-1<n)
  {  start+=size;
     size*=2;
  }
  no=n-(start-1); 
  size/=5;
  flag=no/size;
  if(no%size!=0)
    flag++;
     
  switch(flag)
  { case 1 :{ cout<<"Sheldon"; break;}
    case 2 :{ cout<<"Leonard"; break;}
    case 3 :{ cout<<"Penny"; break;}
    case 4 :{ cout<<"Rajesh"; break;}
    case 5 :{ cout<<"Howard"; break;}
  }
  return 0;  
}