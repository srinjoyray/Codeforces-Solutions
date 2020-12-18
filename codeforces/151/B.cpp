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
{ int n,nos;
  cin>>n;
  vector<string> name;
  string temp_name,s;
  vector<int> v;
  int temp1[n]={0},temp2[n]={0},temp3[n]={0},flag=0,count,pos,max1=0,max2=0,max3=0;
  for(int i=0;i<n;i++)
  { cin>>nos;
    cin>>temp_name;
    name.push_back(temp_name);
    for(int j=1;j<=nos;j++)
     {   v.clear();
         cin>>s; 
         for(int k=0;k<s.size();k++)
             if(s[k]>='0' && s[k]<='9')
                v.push_back(s[k]-'0');
          flag=0;
          for(int k=1;k<v.size();k++)
             if(v[k]!=v[k-1])
               {flag=1;break;}
          if(flag==0)
            {temp1[i]++; max1=std::max(max1,temp1[i]);continue;}
          flag=0;
          for(int k=0;k<v.size()-1;k++)
             if(v[k]<=v[k+1])
               {flag=1;break;}
          if(flag==0)
            {temp2[i]++; max2=std::max(max2,temp2[i]); continue;}
          else
            {temp3[i]++; max3=std::max(max3,temp3[i]);}
     }
  }
  cout<<"If you want to call a taxi, you should call: ";
  count=0;
  for(int i=0;i<n;i++)
    if(temp1[i]==max1)
      {pos=i;count++;}
  for(int i=0;i<n;i++)
    if(temp1[i]==max1)
     { cout<<name[i];
       if(i==pos) 
         cout<<".";
       else
         cout<<", ";
     }
  
  cout<<"\nIf you want to order a pizza, you should call: ";
  count=0;
  for(int i=0;i<n;i++)
    if(temp2[i]==max2)
      {pos=i;count++;}
  for(int i=0;i<n;i++)
    if(temp2[i]==max2)
     { cout<<name[i];
       if(i==pos) 
         cout<<".";
       else
         cout<<", ";
     }
  
  cout<<"\nIf you want to go to a cafe with a wonderful girl, you should call: ";
  count=0;
  for(int i=0;i<n;i++)
    if(temp3[i]==max3)
      {pos=i;count++;}
  for(int i=0;i<n;i++)
    if(temp3[i]==max3)
     { cout<<name[i];
       if(i==pos) 
         cout<<".\n";
       else
         cout<<", ";
     }          
  /*for(int i=0;i<name.size();i++)
    cout<<name[i]<<endl;*/
  return 0;  
}