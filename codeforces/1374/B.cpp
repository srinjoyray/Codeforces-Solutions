#include<iostream>
#include<algorithm>
using namespace std;

int main()
{ int T;
  cin>>T;
  while(T--)
  { long int n,count=0,flag=1;
    cin>>n;  
    while(n>1)
     { 
       if(n%3!=0)
              {flag=0;break;}
       else if(n%6==0)
            {n=n/6;count++;}\
       else
          {n=n/3;count+=2;}
            
         
     }
   if(flag==0)
      cout<<"-1\n";
   else
      cout<<count<<endl;
      
  }
  
  
  return 0;  
}