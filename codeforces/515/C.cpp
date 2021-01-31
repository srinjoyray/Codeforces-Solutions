#include <bits/stdc++.h>
#define lli long long int 
#define mod 1000000007
#define pi 3.141592653589793238
using namespace std;

int main()
{   int t=1;
    //cin>>t;
    lli fact[10];
    fact[0]=1;
    for(int i=1;i<10;i++)
       fact[i]=fact[i-1]*i;
    while(t--)
    { int n;
      cin>>n;
      string s;
      cin>>s;
      lli count,temp;
      lli freq[10]={0};

      for(int i=0;i<n;i++)
      { temp=s[i]-'0';
        if(temp==2)
          freq[2]++;
        else if(temp==3)
          freq[3]++;
        else if(temp==4)
        { freq[2]+=2;
          freq[3]++;
        }
        else if(temp==5)
          freq[5]++;
        else if(temp==6)
        { freq[5]++;
          freq[3]++;
        }
        else if(temp==7)
          freq[7]++;
        else if(temp==8)
        { freq[7]++;
          freq[2]+=3;        
        }  
        else if(temp==9)
        { freq[7]++;
          freq[2]++;
          freq[3]+=2;
        }
        
      }
      for(int i=7;i>=2;)
      { for(int j=1;j<=freq[i];j++)
          cout<<i;
        if(i==3)
          i--;
        else 
          i-=2;
      }
    }  
    
    return 0;  
}