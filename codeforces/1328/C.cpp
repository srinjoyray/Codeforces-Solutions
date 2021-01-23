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
    cin>>t;
    //t=1; 
    while(t--)
    { int n,flag=0;
      cin>>n;
      string s,a,b;
      char ch;
      cin>>s;
      for(int i=0;i<n;i++)
      { ch=s[i];
        if(flag==0)
        {   if(s[i]=='1')
            { a.push_back('1');
              b.push_back('0');  
              flag=1;
            }  
            else if(s[i]=='2')
            { a.push_back('1');
              b.push_back('1');    
            }
            else if(s[i]=='0')
            { a.push_back('0');
              b.push_back('0');  
            }
        }
        else
        {   if(s[i]=='1')
            { a.push_back('0');
              b.push_back('1');  
            }  
            else if(s[i]=='2')
            { a.push_back('0');
              b.push_back('2');    
            }
            else if(s[i]=='0')
            { a.push_back('0');
              b.push_back('0');  
            }
            
        }
      }
      cout<<a<<endl<<b<<endl;
    }  
    
    return 0;  
}