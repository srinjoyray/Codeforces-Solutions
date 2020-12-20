#include <bits/stdc++.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<ctype.h>
#define lli long long int 
#define mod 1000003
#define pi 3.141592653589793238
using namespace std;
int main()
{   int n,k;
    cin>>n>>k;
    int arr[n],flag=0,count=0;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    while(arr[0]!=k)
    { for(int i=0,j;i<n;i++)
      { if(arr[i]>=k)
           break;
        flag=0;
        if(arr[i]==arr[i+1] && i!=n-1)
           flag=1;
        if(flag==1)
           { for(j=i+1;j<n;j++)
               if(arr[i]==arr[j])
                  continue;
               else
                  break;
             i=j-1;      
           }
        
           arr[i]++;
           
      }
     /* for(int i=0;i<n;i++)
         cout<<arr[i]<<" ";
      cout<<endl;*/     
      count++;  
    }
    cout<<count;
    return 0;  
    
}