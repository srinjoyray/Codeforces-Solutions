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
        n*=2;
        int a[n],odd=0,even=0,count=0;
        vector<int> v1,v2;
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n;i++)
        {   if(a[i]%2==0)
            {   even++;
                v1.push_back(i+1);
            }
            else
            {   odd++;
                v2.push_back(i+1);
            }
        }
        
        n/=2;
        
        for(int i=1;i<v2.size() && count<n-1;i+=2)
        {   cout<<v2[i-1]<<" "<<v2[i]<<endl;
            count++;
        }
        for(int i=1;i<v1.size() && count<n-1;i+=2)
        {   cout<<v1[i-1]<<" "<<v1[i]<<endl;
            count++;
        }
       // cout<<"#\n";    
             
    }  
    
    return 0;  
}