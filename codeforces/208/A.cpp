#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

int main()
{ char S[201];
  cin>>S;
  int len,flag=0,first=0;
  len=strlen(S);
  for(int i=0;i<len;i++)
  { if(S[i]=='W' && S[i+1]=='U'  && S[i+2]=='B')
    {   i+=2;
        flag=1;
       
    }
    else
    {   if(flag==1 && first==1)
        { cout<<" "<<S[i];
          flag=0;    
        }
        else
        {  cout<<S[i];
           first=1;
           flag=0; 
        }
    }
      
  }
  return 0;  
}