#include <bits/stdc++.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<ctype.h>
#define lli long long int 
#define mod 1000000007
using namespace std;
#define pi 3.141592653589793238

int main()
{ int n,m;
  cin>>n;
  m=100001;
  int arr[n],last_pos[m],diff[m]={0},freq[m]={0},unique=0;
  for(int i=0;i<n;i++)
      cin>>arr[i];
  for(int i=1;i<=m;i++)
     last_pos[i]=-1;
  for(int i=0;i<n;i++)
  { if(freq[arr[i]]==-1)
         continue;
    else if(freq[arr[i]]==0)
      { freq[arr[i]]=1;
        last_pos[arr[i]]=i;  
      }
    else if(freq[arr[i]]==1)
      { diff[arr[i]]=i-last_pos[arr[i]];
        last_pos[arr[i]]=i;
        freq[arr[i]]++;
      }
    else
      { if(i-last_pos[arr[i]]==diff[arr[i]])
           last_pos[arr[i]]=i;
        else
           freq[arr[i]]=-1;
      }
  }
  for(int i=1;i<=m;i++)
    if(freq[i]>0)
      unique++;
  cout<<unique<<endl;
  for(int i=1;i<=m;i++)
    if(freq[i]>0)
       cout<<i<<" "<<diff[i]<<endl;
  return 0;  
}