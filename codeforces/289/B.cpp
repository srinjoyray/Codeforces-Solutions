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
{ int n,m,d,temp,sum=0,min=INT_MAX;
  cin>>n>>m>>d;
  vector <int> v;
  for(int i=0;i<n;i++)
     for(int j=0;j<m;j++)
       { cin>>temp; v.push_back(temp);}
  sort(v.begin(),v.end());
  for(int i=1;i<v.size();i++)
    if((v[i]-v[i-1])%d!=0)
      {cout<<"-1";return 0;}
  if(v.size()==1)
    {cout<<"0";return 0;}
  else if(v.size()==2)
    {cout<<(v[1]-v[0])/d;return 0;}
  int left[v.size()],right[v.size()];
  left[0]=0; right[v.size()-1]=0;
  for(int i=1;i<v.size();i++)
     left[i]=left[i-1]+i*(v[i]-v[i-1]);
  for(int i=v.size()-2;i>=0;i--)
     right[i]=right[i+1]+(v.size()-2-i+1)*(v[i+1]-v[i]);
  for(int i=1;i<v.size()-1;i++)
    { temp=(left[i]/d) + (right[i]/d);
      min=std::min(min,temp);
    }
 /* for(int i=0;i<v.size();i++)
    cout<<left[i]<<" "<<right[i]<<endl;*/
  cout<<min;    
  return 0;  
}