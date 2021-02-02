#include <bits/stdc++.h>
#define lli long long int 
#define mod 1000000007
#define pi 3.141592653589793238
using namespace std;

int main()
{   int t=1;
    cin>>t;
    while(t--)
    {   int n;
        cin>>n;
        lli a[n],m;
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n;i++)
        { m=abs(a[i]);
          if(i%2==0)
            cout<<m<<" ";
          else
            cout<<-m<<" ";
        } 
        cout<<endl;
        
    }  
    
    return 0;  
}