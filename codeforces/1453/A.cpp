#include <bits/stdc++.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<ctype.h>
using namespace std;
 
int main()
{ int t;
  cin>>t;
  while(t--)
  { int n,m,i,j,count=0;
    cin>>n>>m;
    int a[n],b[m];
    for(i=0;i<n;i++)
       cin>>a[i];
    for( j=0;j<m;j++)
       cin>>b[j];
     i=0; j=0;   
    while(i<n && j<m)
    { if(a[i]==b[j])
       {count++;i++;j++;}
      else if(a[i]>b[j]) 
        j++;
      else
        i++;
        
    }
    cout<<count<<endl;    
      
  }
 
  return 0;  
}