#include <bits/stdc++.h>
#define lli long long int 
#define mod 1000000007
#define pi 3.141592653589793238
using namespace std;

int main()
{   int t=1;
    cin>>t;
    while(t--)
    {   string s;
        cin>>s;
        int n,count,min;
        n=s.size();
        min=n;
        for(int i=0;i<n;i++)
        { count=0; //cout<<i<<endl;
          for(int j=0;j<n;j++)
          { if(j<=i && s[j]=='1')
              count++;
            else if(j>i && s[j]=='0')
              count++;
           // cout<<j<<" "<<count<<endl;  
          }   // cout<<count<<" ";
          min=std::min(min,count);
          count=0;
          for(int j=0;j<n;j++)
          { if(j<=i && s[j]=='0')
              count++;
            else if(j>i && s[j]=='1')
              count++;
          }    //cout<<count<<endl;
          min=std::min(min,count);
        }
        cout<<min<<endl;
    }  
    
    return 0;  
}