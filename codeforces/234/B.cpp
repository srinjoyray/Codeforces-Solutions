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
{ freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  int n,k;
  cin>>n>>k;
  int arr[n],copy[n];
  for(int i=0;i<n;i++)
     {cin>>arr[i];copy[i]=arr[i];}
  sort(arr,arr+n,greater<int>() );
  cout<<arr[k-1]<<endl;
  for(int i=0;i<k;i++)
  { for(int j=0;j<n;j++)
       if(arr[i]==copy[j])
         {cout<<j+1<<" ";copy[j]=-1;break;}
  }
  return 0;  
}