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
  cin>>n>>m;
  int a[m],b[m],freq[n+1]={0},pos;
  for(int i=0;i<m;i++)
    { cin>>a[i]>>b[i];
      freq[a[i]]++;
      freq[b[i]]++;
    }
  for(int i=1;i<=n;i++)
    if(freq[i]==0)
      {pos=i;break;}
  cout<<n-1<<endl;
  for(int i=1;i<=n;i++)
   { if(i==pos)
        continue;
     cout<<pos<<" "<<i<<endl;        
   }
  return 0;  
}