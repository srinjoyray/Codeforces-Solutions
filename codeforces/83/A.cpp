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
{   lli n,temp,count;
    cin>>n;
    lli arr[n];
    for(int i=0;i<n;i++)
       cin>>arr[i];
    count=n;   
    for(int i=0,j;i<n;i++)
    { j=i+1;
      while(j<n && arr[j]==arr[i])
        j++;
      temp=j-i;
      i=j-1;
      count+=(temp*(temp-1))/2;
    }
    cout<<count<<endl;
    return 0;  
}