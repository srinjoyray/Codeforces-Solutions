#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

int main()
{ int q;
  cin>>q;
  while(q--)
  { int n,k,*max,*min;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)
       cin>>a[i];
    max=max_element(a,a+n);   
    min=min_element(a,a+n);
    if(*max-*min>k*2)
       cout<<"-1\n";
    else
       cout<<*min+k<<endl;
  }
  return 0;  
}