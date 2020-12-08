#include <bits/stdc++.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<ctype.h>
using namespace std;

int main()
{ int n;
  cin>>n;
  int x[n],y[n],count,store[100001]={0};
  for(int i=0;i<n;i++)
    cin>>x[i]>>y[i];
   for(int i=0;i<n;i++)
      store[x[i]]++;
   for(int i=0;i<n;i++)    
     { count=store[y[i]];     
       cout<<count+n-1<<" "<<n-1-count<<endl;  
     }
  return 0;  
}