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
{ int n,k,total;
  cin>>n>>k;
  int arr[n+1],x=n;
  for(int i=1;i<=n;i++)
     arr[i]=i;
  if(n==k)
   {cout<<"-1";return 0;}
  total=n-1-k;
  if(total%2==1)
    {arr[2]=1;arr[1]=2;total--;}
  while(total)
  { arr[x]=x-1;
    arr[x-1]=x;
    x-=2;
    total-=2;  
  }
  for(int i=1;i<=n;i++)
     cout<<arr[i]<<" ";
  return 0;  
}