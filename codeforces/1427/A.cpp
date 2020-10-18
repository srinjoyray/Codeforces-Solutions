#include<iostream>
#include<algorithm>
using namespace std;

int main()
{ int T;
  cin>>T;
  while(T--)
  { int n,sum=0,flag=0;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    sort(arr,arr+n);    
    for(int i=0;i<n;i++)
        {sum+=arr[i];
         if(arr[i]!=0)
            flag=1;
        }
       
    if(flag==0 || sum==0)
       cout<<"NO\n";
    else 
       { cout<<"YES\n";
         if(sum>0)
          { for(int i=n-1;i>=0;i--)
                cout<<arr[i]<<" ";
            cout<<endl;  
          }
         else
          { for(int i=0;i<n;i++)
                cout<<arr[i]<<" ";
            cout<<endl;
              
          }
       }
  }
  
  
  return 0;  
}