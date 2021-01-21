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
    { int N;
      cin>>N;
      lli T,a[N],ans[N],count=0;
      cin>>T;
      for(int i=0;i<N;i++)
          cin>>a[i];
      if(T%2==1)      
      { for(int i=0;i<N;i++)
        { if(a[i]<=T/2)
            ans[i]=1;
          else
            ans[i]=0;
        }
      }
      else
      { for(int i=0;i<N;i++) 
        { if(a[i]<T/2)
            ans[i]=1;
          else if(a[i]>T/2)    
            ans[i]=0;
          else
          { ans[i]=count%2;
            count++;  
          }
        }  
      }
      for(int i=0;i<N;i++)
         cout<<ans[i]<<" ";
      cout<<endl;     
    }  
    
    return 0;  
}