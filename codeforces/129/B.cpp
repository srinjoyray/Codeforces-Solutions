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
{ int n,m;
  cin>>n>>m;
  int a[m+1],b[m+1],freq[n+1]={0},count=0,flag=1;
  vector<int> v;
  /*for(int i=1;i<=n;i++)
    freq[i]=0;*/
  for(int i=1;i<=m;i++)
    cin>>a[i]>>b[i];
  for(int i=1;i<=m;i++)
  { freq[a[i]]++;
    freq[b[i]]++;  
  }
  /*for(int i=1;i<=n;i++)
    cout<<freq[i]<<" "; cout<<endl;*/
    
  for(int i=1;i<=n;i++)
      if(freq[i]==1)
        {flag=0;break;}
      
  while(flag==0)
  { flag=1;
    v.clear();
    for(int i=1;i<=n;i++)
      if(freq[i]==1)
        {flag=0;v.push_back(i);}
    if(flag==1)
      break;
    /*for(int i=0;i<v.size();i++)
       cout<<v[i]<<" ";
    cout<<endl;   */
    for(int i=0;i<v.size();i++)
        { for(int j=1;j<=m;j++)
            { if(a[j]==v[i] || b[j]==v[i])
                { freq[a[j]]--; freq[b[j]]--;
                  a[j]=-1; b[j]=-1;
                  break;
                }
                 
            }
        }
    count++;    
  }
  cout<<count<<endl;
  return 0;  
}