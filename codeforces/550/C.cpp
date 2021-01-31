#include <bits/stdc++.h>
#define lli long long int 
#define mod 1000000007
#define pi 3.141592653589793238
using namespace std;

int main()
{   int t=1;
    //cin>>t;
    while(t--)
    { string s;
      cin>>s;
      int flag=1,n,num;
      n=s.size();
      for(int i=n-1;i>=0;i--)
         if(s[i]%2==0)
           { s=s.substr(0,i+1);
             break;
           }     
      n=s.size();       
      for(int i=0;i<n;i++)
         if(s[i]=='0' || s[i]=='8')
          { flag=s[i]-'0'; break; }
      if(flag!=1) 
      { cout<<"YES\n";
        cout<<flag<<endl; 
        continue;
      }
      if(n==0)
      { cout<<"NO\n";
        continue;  
      }
      for(int i=0;i<n;i++)
      { for(int j=i+1;j<n;j++)
         { num=((s[i]-'0')*10)+(s[j]-'0');
           if(num%8==0)
           { flag=0; break;}    
         }
         if(flag==0)
           break;
      }     
      if(flag==0)
      { cout<<"YES\n";
        cout<<num<<endl; 
        continue;
          
      }
      for(int i=0;i<n;i++)
      { for(int j=i+1;j<n;j++)
        { for(int k=j+1;k<n;k++)
           { num=100*(s[i]-'0')+ 10*(s[j]-'0')+(s[k]-'0');
             if(num%8==0)
             { flag=0; break;}    
           }   
          if(flag==0)
           break; 
        }
        if(flag==0)
           break;  
      }    
      if(flag==0)
      { cout<<"YES\n";
        cout<<num<<endl; 
        continue;
      }  
      else
       cout<<"NO\n";
    }  
    
    return 0;  
}