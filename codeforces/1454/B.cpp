#include <bits/stdc++.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<ctype.h>
using namespace std;
 
int main()
{ int t;
  cin>>t;
  while(t--)
  { int n,i;
    cin>>n;
    int arr[n],a[n],num;
    for(i=0;i<n;i++)
      { cin>>a[i];
        arr[i]=a[i];
      }    
    sort(arr,arr+n);
    for(i=0;i<n;i++)
     { if(i==0)
        { if(arr[i]!=arr[i+1])
          {num=arr[i]; break;}
        }
       else if(i==n-1)
        { if(arr[i]!=arr[i-1])
           {num=arr[i]; break;}  
        }
       else
        { if(arr[i]!=arr[i-1] && arr[i]!=arr[i+1])
            {num=arr[i]; break;}   
        }
     }
    if(i==n)
      {cout<<"-1\n";continue;}
    for(int i=0;i<n;i++)
      if(a[i]==num)
        cout<<i+1<<endl;
  }
  return 0;  
}