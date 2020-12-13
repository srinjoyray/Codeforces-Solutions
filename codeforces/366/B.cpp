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
{ int n,k;
  cin>>n>>k;
  int arr[n],min=INT_MAX,pos,temp;
  for(int i=0;i<n;i++)
     cin>>arr[i];
  for(int i=0;i<k;i++)     
  { temp=0;
    for(int j=i;j<n;j+=k)
        temp+=arr[j];
    if(min>temp)
      {min=temp;pos=i+1;}
    //cout<<temp<<endl;  
  }
  cout<<pos;
  return 0;  
}