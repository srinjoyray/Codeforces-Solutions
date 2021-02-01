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
        lli a[n],count=0;
        for(int i=0;i<n;i++)
           cin>>a[i];
        for(int i=0;i<n-1;i++)
        { if(a[i]<=a[i+1])
            continue;
          else
            count+=a[i]-a[i+1];
        }
        cout<<count<<endl;
    }  
    
    return 0;  
}