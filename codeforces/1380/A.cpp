#include<iostream>
#include<algorithm>
using namespace std;

int main()
{ int T;
  cin>>T;
  while(T--)
  { int n,i,flag=0;
    cin>>n;
    int arr[n];
    for( i=0;i<n;i++)
       cin>>arr[i];
    for(i=1;i<n-1;i++)
        if(arr[i]>arr[i-1] && arr[i]>arr[i+1])
           {flag=1;break;}
    if(flag==0)
       cout<<"NO\n";
    else
      { cout<<"YES\n";
        cout<<i<<" "<<i+1<<" "<<i+2<<endl;
          
      }
  }
  
  
  return 0;  
}