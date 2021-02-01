#include <bits/stdc++.h>
#define lli long long int 
#define mod 1000000007
#define pi 3.141592653589793238
using namespace std;

int main()
{   int t=1;
    //cin>>t;
    while(t--)
    {   int n;
        cin>>n;
        int a[n],zero=0,five=0,num;
        for(int i=0;i<n;i++)
        {   cin>>a[i];
            if(a[i]==0)
                zero++;
            else
                five++;
        }
        num=five/9;
        if(zero==0)
          cout<<"-1\n";
        else if(num==0)
          cout<<0<<endl;
        else
        { for(int i=1;i<=num;i++)
            for(int j=1;j<=9;j++)
              cout<<5;
          for(int i=1;i<=zero;i++)
              cout<<0;
          cout<<endl;      
        }
    }  
    
    return 0;  
}