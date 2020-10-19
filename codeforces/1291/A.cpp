#include<iostream>
#include<algorithm>
using namespace std;

int main()
{ int T;
  cin>>T;
  while(T--)
  { int n,flag=0;
    cin>>n;
    char str[n+1],ans[3]={'0'};
    cin>>str;
    for(int i=0;str[i]!='\0';i++)
        { if(str[i]%2==1)
             { if(ans[0]=='0')
                  ans[0]=str[i];
               else      
                  ans[1]=str[i];
                 
               if(flag==0)
                 flag=1;
               else if(flag==1)
                 {flag=2;break;}
                 
             }
            
        }
    if(flag==2)
       cout<<ans[0]<<ans[1]<<endl;
    else 
       cout<<"-1\n";
      
  }
  
  
  return 0;  
}